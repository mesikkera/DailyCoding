# Firestore Data Model: Personal Productivity Todo App

- Status: Draft
- Date: 2026-06-23
- Related decisions:
  - `docs/decisions/0001-baas-firebase.md`
  - `DESIGN.md`

## Design goals

This model supports the agreed product requirements:

- Personal account first, future sharing/collaboration later.
- Today Board is status-first Kanban.
- Tasks and calendar events are separate concepts.
- Daily achievement rate counts tasks only.
- On-hold tasks and calendar events are excluded from achievement-rate calculations.
- Carry-over moves a task to the destination date; the destination date owns the achievement accounting.
- Offline task viewing/editing is required; online return syncs changes.
- Default conflict rule: last modified version wins.
- Browser push first; native push later.
- Daily, weekly, and monthly achievement summaries.

## Firestore modeling principles

- Use small JSON-like documents in collections.
- Keep frequently queried screen data easy to fetch for Today Board and Calendar.
- Denormalize display fields where it avoids expensive multi-document reads.
- Precompute daily/weekly/monthly stats documents instead of scanning all historical tasks on every load.
- Use `updatedAt` and `clientUpdatedAt` consistently because conflict resolution is last-modified-wins.
- Use soft delete for user-facing data in MVP (`deletedAt`) so offline deletes can sync safely.

## Top-level structure

```text
users/{userId}
  profile
  settings
  categories/{categoryId}
  tasks/{taskId}
  events/{eventId}
  recurrenceRules/{ruleId}
  notificationSubscriptions/{subscriptionId}
  statsDaily/{yyyy-mm-dd}
  statsWeekly/{yyyy-Www}
  statsMonthly/{yyyy-mm}
  holidays/{yyyy-mm-dd}             optional user-visible cache/override
  syncMetadata/{deviceId}           optional client sync diagnostics
```

Why user-scoped subcollections:

- The MVP is single-user after login.
- Security rules can naturally restrict reads/writes to `request.auth.uid == userId`.
- Future collaboration can be added with `workspaces/{workspaceId}` later without blocking MVP.

## Common fields

Most user-owned documents should include:

```ts
{
  id: string,                 // same as Firestore document ID when convenient
  userId: string,
  createdAt: Timestamp,       // server timestamp when possible
  updatedAt: Timestamp,       // server timestamp when possible
  clientUpdatedAt: Timestamp, // client clock; used for last-modified-wins intent
  deletedAt: Timestamp | null,
  schemaVersion: number
}
```

Notes:

- `updatedAt` is authoritative once synced.
- `clientUpdatedAt` helps preserve offline edit intent before server confirmation.
- If a document receives competing changes, the app should resolve by latest modification time and only show conflict UI when automatic resolution is risky or fails.

## `users/{userId}`

Purpose: root profile and account metadata.

```ts
{
  displayName: string,
  email: string | null,
  photoURL: string | null,
  locale: 'ko-KR',
  timezone: 'Asia/Seoul',
  defaultCalendarView: 'week',
  createdAt: Timestamp,
  updatedAt: Timestamp
}
```

## `users/{userId}/settings/app`

Purpose: user preferences that affect product behavior.

```ts
{
  categoryOrder: string[],
  defaultTaskStatus: 'planned',
  defaultTaskPriority: 'normal',
  carryOver: {
    enabled: boolean,
    defaultTarget: 'tomorrow' | 'choose-date'
  },
  achievement: {
    excludeOnHold: true,
    includeEvents: false
  },
  notifications: {
    browserPushEnabled: boolean,
    quietHours?: { start: string, end: string }
  },
  calendar: {
    defaultView: 'week',
    showKoreanHolidays: true
  },
  updatedAt: Timestamp
}
```

## `categories/{categoryId}`

Purpose: configurable category groups like 생활, 업무, 자기 계발.

```ts
{
  name: string,
  color: string,              // semantic token or hex
  order: number,
  archivedAt: Timestamp | null,
  createdAt: Timestamp,
  updatedAt: Timestamp,
  clientUpdatedAt: Timestamp,
  deletedAt: Timestamp | null,
  schemaVersion: 1
}
```

Today Board usage:

- Cards show category chip/color.
- Board remains status-first; categories are filters and metadata.

## `tasks/{taskId}`

Purpose: achievement-tracked work item.

```ts
{
  title: string,
  description: string | null,
  categoryId: string | null,

  scheduledDate: 'yyyy-mm-dd',
  originalScheduledDate: 'yyyy-mm-dd' | null,
  carriedOverFromTaskId: string | null,
  carryOverCount: number,

  status: 'planned' | 'in_progress' | 'on_hold' | 'completed',
  priority: 'high' | 'normal' | 'low',

  recurrenceRuleId: string | null,
  generatedForDate: 'yyyy-mm-dd' | null,

  reminder: {
    enabled: boolean,
    remindAt: Timestamp | null,
    channel: 'browser_push'
  },

  completedAt: Timestamp | null,
  sortOrder: number,

  createdAt: Timestamp,
  updatedAt: Timestamp,
  clientUpdatedAt: Timestamp,
  deletedAt: Timestamp | null,
  schemaVersion: 1
}
```

Key rules:

- Achievement denominator includes statuses: `planned`, `in_progress`, `completed`.
- Achievement numerator includes status: `completed`.
- `on_hold` is excluded.
- Calendar events are never included.
- Carry-over updates `scheduledDate` to the new date.
- If preserving movement history becomes important, add a task activity log later.

Primary queries:

```text
tasks where scheduledDate == today and deletedAt == null order by status, sortOrder
tasks where scheduledDate between weekStart and weekEnd and deletedAt == null
tasks where recurrenceRuleId == X and generatedForDate == date
```

Index implications:

- `scheduledDate + deletedAt + status + sortOrder`
- `scheduledDate + deletedAt + categoryId`
- `recurrenceRuleId + generatedForDate`

## `events/{eventId}`

Purpose: calendar event. Events are separate from tasks and do not affect achievement rate.

```ts
{
  title: string,
  description: string | null,
  location: string | null,

  startsAt: Timestamp,
  endsAt: Timestamp,
  allDay: boolean,
  timezone: 'Asia/Seoul',

  recurrenceRuleId: string | null,

  reminder: {
    enabled: boolean,
    remindAt: Timestamp | null,
    channel: 'browser_push'
  },

  color: string | null,

  createdAt: Timestamp,
  updatedAt: Timestamp,
  clientUpdatedAt: Timestamp,
  deletedAt: Timestamp | null,
  schemaVersion: 1
}
```

Primary queries:

```text
events where startsAt < rangeEnd and endsAt > rangeStart and deletedAt == null
```

Calendar display:

- Week view is default.
- Day/month views also exist.
- South Korean holidays are displayed separately from user events.

## `recurrenceRules/{ruleId}`

Purpose: template/rule for recurring tasks or events.

```ts
{
  type: 'task' | 'event',
  title: string,
  template: map,              // fields copied into generated task/event

  frequency: 'daily' | 'weekly' | 'monthly',
  interval: number,
  daysOfWeek: number[] | null, // 0-6, for weekly rules
  dayOfMonth: number | null,

  startsOn: 'yyyy-mm-dd',
  endsOn: 'yyyy-mm-dd' | null,
  timezone: 'Asia/Seoul',

  active: boolean,
  lastGeneratedForDate: 'yyyy-mm-dd' | null,

  createdAt: Timestamp,
  updatedAt: Timestamp,
  clientUpdatedAt: Timestamp,
  deletedAt: Timestamp | null,
  schemaVersion: 1
}
```

MVP recurrence scope:

- Daily routines must work first.
- Weekly/monthly can be enabled after the basic generation path is stable.

Generation rule:

- A scheduled function or client-safe idempotent routine creates generated tasks/events for a target date.
- Prevent duplicates using `recurrenceRuleId + generatedForDate`.

## `notificationSubscriptions/{subscriptionId}`

Purpose: browser push token/subscription first; native push later.

```ts
{
  platform: 'web' | 'ios' | 'android',
  provider: 'fcm',
  token: string,
  deviceName: string | null,
  userAgent: string | null,
  enabled: boolean,
  lastSeenAt: Timestamp,
  createdAt: Timestamp,
  updatedAt: Timestamp,
  deletedAt: Timestamp | null,
  schemaVersion: 1
}
```

## Stats documents

Stats are precomputed or incrementally maintained so dashboard/calendar views are fast.

### `statsDaily/{yyyy-mm-dd}`

```ts
{
  date: 'yyyy-mm-dd',
  plannedCount: number,
  inProgressCount: number,
  completedCount: number,
  onHoldCount: number,
  denominatorCount: number,   // planned + inProgress + completed
  achievementRate: number,    // completed / denominator, 0-1
  carriedOverInCount: number,
  carriedOverOutCount: number,
  recurringGeneratedCount: number,
  categoryBreakdown: {
    [categoryId: string]: {
      plannedCount: number,
      inProgressCount: number,
      completedCount: number,
      onHoldCount: number,
      achievementRate: number
    }
  },
  updatedAt: Timestamp,
  schemaVersion: 1
}
```

### `statsWeekly/{yyyy-Www}`

```ts
{
  weekId: 'yyyy-Www',
  startsOn: 'yyyy-mm-dd',
  endsOn: 'yyyy-mm-dd',
  averageAchievementRate: number,
  completedCount: number,
  denominatorCount: number,
  dailyRates: { [date: string]: number },
  updatedAt: Timestamp,
  schemaVersion: 1
}
```

### `statsMonthly/{yyyy-mm}`

```ts
{
  monthId: 'yyyy-mm',
  averageAchievementRate: number,
  completedCount: number,
  denominatorCount: number,
  dailyRates: { [date: string]: number },
  updatedAt: Timestamp,
  schemaVersion: 1
}
```

Aggregation strategy:

- Client can calculate optimistic local summaries for immediate UI updates.
- Cloud Functions should recompute canonical summaries after task writes.
- For MVP, daily stats can be recomputed from all tasks for that date; weekly/monthly stats can aggregate daily docs.

## South Korean holidays

Options:

1. Static app-bundled holiday data by year.
2. Server-side yearly import into a public collection.
3. External API integration later.

Recommended MVP:

```text
publicHolidaysKR/{yyyy-mm-dd}
```

```ts
{
  date: 'yyyy-mm-dd',
  nameKo: string,
  nameEn: string | null,
  type: 'national' | 'substitute' | 'other',
  source: string,
  year: number
}
```

This should be read-only for clients.

## Security rules direction

MVP rule shape:

```text
/users/{userId}/... readable/writable only by authenticated userId
/publicHolidaysKR/... readable by authenticated users, writable only by admin/server
```

Future collaboration direction:

- Add `workspaces/{workspaceId}`.
- Add membership/role documents.
- Move or mirror shareable tasks/events into workspace-scoped collections.

## Offline and sync behavior

Client requirements:

- Enable Firestore persistent cache for web after user consent/trusted-device handling.
- Show sync state for offline edits.
- Allow task viewing/editing while offline.
- Use `clientUpdatedAt` and mutation metadata to display pending changes.
- Default conflict behavior remains last-modified-wins.

Important implementation caveat:

- Firestore transactions fail offline, so offline UI should avoid transaction-dependent task edits. Use simple document writes or batched writes where possible; recompute canonical stats server-side after sync.

## Open implementation questions

- Exact native app stack later: Swift/Kotlin, React Native, Flutter, or another path.
- Whether to store tasks under `users/{userId}/tasks` forever or migrate to `workspaces/{workspaceId}/tasks` before collaboration.
- Whether recurring event support is MVP or phase 2 after recurring tasks.
- Whether holiday data should be bundled, imported yearly, or fetched from an external API.
- Whether statistics should use weighted completion rates or simple average of daily rates for weekly/monthly display.

## References

- Firestore data model: https://firebase.google.com/docs/firestore/data-model
- Firestore transactions and batched writes: https://firebase.google.com/docs/firestore/manage-data/transactions
- Firestore queries: https://firebase.google.com/docs/firestore/query-data/queries
- Firestore offline persistence: https://firebase.google.com/docs/firestore/manage-data/enable-offline
