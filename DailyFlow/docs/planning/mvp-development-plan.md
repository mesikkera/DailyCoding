# DailyFlow MVP Development Plan

- Status: Draft
- Date: 2026-06-23
- Scope: MVP implementation planning, not source implementation yet.
- Source documents:
  - `DailyFlow/DESIGN.md`
  - `DailyFlow/docs/decisions/0001-baas-firebase.md`
  - `DailyFlow/docs/technical/firestore-data-model.md`
  - `DailyFlow/docs/planning/interview-context.md`

## 1. MVP definition

DailyFlow MVP is the smallest usable version of the product that lets the user:

1. Sign in with a social account.
2. Open the Today Board.
3. Create, edit, move, hold, and complete tasks.
4. See automatic daily achievement rate.
5. Use configurable categories and priorities.
6. Carry unfinished tasks to another date.
7. Generate daily recurring routine tasks.
8. View and edit calendar events.
9. Use week-first calendar with day/month alternatives and Korean holidays.
10. Receive browser push reminders.
11. View daily, weekly, and monthly achievement statistics.
12. View and edit tasks offline, then sync online.

The MVP is not complete until Today Board is useful as the daily home surface.

## 2. Non-MVP / later scope

Defer these until after MVP validation:

- Native iOS/Android apps.
- Email, Telegram, and native mobile push notifications.
- Sharing/collaboration UI.
- Advanced analytics beyond daily/weekly/monthly achievement.
- External calendar import/export.
- Complex recurrence such as exceptions, skipped occurrences, and custom RRULE editing.
- Full conflict-resolution UI beyond basic last-modified-wins and recoverable error messaging.

## 3. Recommended implementation phases

### Phase 0 — Project scaffold and engineering baseline

Goal: create a clean DailyFlow app workspace isolated from older repository examples.

Deliverables:

- Web app scaffold under `DailyFlow/`.
- Package manager choice and lockfile.
- TypeScript enabled.
- Lint, format, test, and build scripts.
- App shell with placeholder routes.
- Firebase client initialization isolated behind an app service module.
- Basic CI-ready commands documented in `DailyFlow/README.md`.

Acceptance criteria:

- `npm test` or equivalent passes.
- `npm run build` or equivalent passes.
- App can render a placeholder Today route locally.
- No source files are placed in repository root.

Verification:

- Run install/build/test commands.
- Confirm generated files are all under `DailyFlow/`.

### Phase 1 — Product shell and visual system

Goal: establish the Apple Calendar/Reminders-inspired UI foundation before feature depth.

Deliverables:

- App layout/navigation: Today, Calendar, Stats, Settings.
- Design tokens for color, typography, spacing, radius, status, priority, category, sync state.
- Reusable components:
  - Button
  - Card
  - Form field
  - Modal/drawer
  - Status chip
  - Priority indicator
  - Category chip
  - Empty/error/loading states
- Responsive layout baseline for desktop, tablet, and mobile web.

Acceptance criteria:

- Today route has the final intended page regions, even if backed by mock data.
- Status colors and priority indicators match `DESIGN.md`.
- Components remain readable on mobile width.
- Keyboard focus is visible.

Verification:

- Manual responsive check at desktop/tablet/mobile widths.
- Component-level tests where practical.
- Screenshot capture for Today route baseline.

### Phase 2 — Authentication and user bootstrap

Goal: enable personal cloud-backed usage.

Deliverables:

- Firebase project configuration placeholders.
- Firebase Authentication integration.
- Google login.
- Apple login path documented or implemented, depending on credentials availability.
- User document bootstrap at `users/{userId}`.
- Default settings and default categories created for a new user.

Acceptance criteria:

- User can sign in and sign out.
- After first sign-in, `users/{userId}` exists.
- Default categories can be loaded from Firestore.
- Authenticated routes are protected.

Verification:

- Emulator or test Firebase project auth smoke test.
- Unit tests for user bootstrap logic.
- Manual sign-in/sign-out test.

### Phase 3 — Task model and Today Board core

Goal: make the main product surface usable.

Deliverables:

- Firestore task repository/service.
- Task create/edit/delete.
- Task status transitions:
  - planned
  - in_progress
  - on_hold
  - completed
- Priority:
  - high
  - normal
  - low
- Category assignment.
- Date-first category Kanban Today Board.
- Category filter/chip display.
- Daily count and achievement-rate calculation.

Acceptance criteria:

- Creating a task for today appears in the planned lane.
- Moving a task between status lanes updates counts immediately.
- Completing a task changes daily achievement rate.
- On-hold tasks are excluded from denominator.
- Calendar events are not included in achievement rate.
- Priority and category are visible on task cards.

Verification:

- Unit tests for achievement formula:
  - `completed / (planned + in_progress + completed)`
  - exclude `on_hold`
  - exclude events
- Integration tests for task CRUD against Firebase emulator.
- Manual Today Board smoke test.

### Phase 4 — Offline task behavior and sync indicators

Goal: satisfy the offline-first task requirement before adding more feature surfaces.

Status: complete in the first local/PWA slice. Firestore persistent cache is enabled at app initialization, Today Board edits are marked as pending local changes, and the UI exposes online/offline and sync states. A later Firebase-backed integration pass should replace the current demo "sync complete" control with real write acknowledgement handling.

Deliverables:

- Firestore persistent cache enabled for trusted web sessions.
- Offline status indicator.
- Pending sync indicator for local task changes.
- Last-modified-wins metadata handling with `clientUpdatedAt`.
- Basic recoverable error UI for sync failures.

Acceptance criteria:

- User can load existing tasks, go offline, edit a task, and see the local edit.
- When online returns, the change syncs.
- UI shows pending sync state while offline.
- Last-modified-wins behavior is documented and covered by tests where feasible.

Verification:

- Browser devtools offline simulation.
- Emulator-backed integration test for metadata handling if practical.
- Manual two-session conflict smoke test.

### Phase 5 — Carry-over and recurring routines

Goal: reduce daily manual bookkeeping.

Status: domain and Today Board slice complete. Tasks can be carried to tomorrow from the card actions, task records retain original schedule/carry-over count, and daily recurrence rule generation is idempotent by `recurrenceRuleId + generatedForDate`.

Deliverables:

- Carry-over action from task card/detail.
- Move unfinished task to tomorrow or chosen date.
- Recurrence rule model for daily task routines.
- Idempotent daily task generation from recurrence rules.
- Duplicate prevention by `recurrenceRuleId + generatedForDate`.

Acceptance criteria:

- Carrying a task to another date changes its `scheduledDate`.
- Carried-over task appears on destination date and affects destination date achievement.
- Carried-over task no longer affects original date's active achievement calculation.
- Daily recurring task appears once per date.
- Reopening the app does not duplicate generated routine tasks.

Verification:

- Unit tests for carry-over date reassignment.
- Unit/integration tests for recurrence duplicate prevention.
- Manual Today Board date-switch smoke test.

### Phase 6 — Calendar MVP

Goal: provide week-first schedule and productivity context.

Status: first interactive calendar slice complete. The route defaults to the current week view, supports day/week/month toggles, shows a weekly achievement summary above a 00:00–24:00 hourly timetable with a fixed time axis and side-wheel date-column scrolling, can add/edit/delete events with reminder metadata, shows fixed-date Korean holiday labels, and displays daily achievement/task distribution placeholders.

Deliverables:

- Calendar route.
- Week view as default.
- Week view with top achievement summary and hourly 00:00–24:00 schedule grid.
- Day and month view toggles.
- Calendar event create/edit/delete.
- Event reminders data field.
- Korean holiday display.
- Task distribution and daily achievement indicators on calendar days.

Acceptance criteria:

- Week view loads by default.
- Calendar entry starts from the current week.
- Weekly timetable keeps the time axis fixed while date columns scroll horizontally.
- User can create an event with start/end time.
- User can edit and delete an event.
- Event appears in calendar but does not affect achievement rate.
- Day/month views are available.
- Korean holidays are visible.
- Dates show daily achievement rate or clear placeholder if stats are not ready.

Verification:

- Unit tests for date-range helpers.
- Integration tests for event CRUD.
- Manual calendar view switching test.

### Phase 7 — Statistics MVP

Goal: make progress visible beyond one day.

Status: first route/domain slice complete. The stats route shows daily rows, weekly and monthly average summaries, and a canonical daily stats payload helper that excludes on-hold tasks and calendar events from the denominator.

Deliverables:

- Daily stats document update strategy.
- Weekly average achievement view.
- Monthly average achievement view.
- Stats route with clear summaries.
- Optional optimistic client summary while canonical stats sync.

Acceptance criteria:

- Daily stat shows planned/in progress/completed/on-hold counts.
- Weekly average is shown.
- Monthly average is shown.
- Stats match task-only achievement rules.
- On-hold and events remain excluded.

Verification:

- Unit tests for daily/weekly/monthly aggregation.
- Firestore emulator tests for stats recomputation path.
- Manual comparison with known fixture data.

### Phase 8 — Browser push notifications

Goal: implement the MVP notification channel.

Status: client/settings slice complete. Settings exposes the browser notification permission flow, browser push enable/disable state, a test notification action, and a Firestore `notificationSubscriptions` repository for storing FCM subscription records. Real FCM token issuance and backend reminder delivery remain integration work.

Deliverables:

- Notification permission flow.
- FCM web token/subscription storage.
- Reminder scheduling backend path.
- Browser push for task/event reminders.
- Notification settings UI.

Acceptance criteria:

- User can grant/deny notification permission.
- Token is stored under `notificationSubscriptions`.
- User can enable/disable browser push.
- A test reminder can be delivered in supported browsers.
- Failure states are visible and recoverable.

Verification:

- Manual browser push test.
- Firebase emulator or test project function test where possible.
- Permission denied/revoked state test.

### Phase 9 — MVP hardening and release readiness

Goal: make the MVP safe to use daily.

Status: started. Added a user-scoped Firestore rules draft, security documentation, and Vite manual chunking/size threshold so release builds separate Firebase SDK weight from app code. Emulator rule tests and field-level validation remain before public beta.

Deliverables:

- Security rules for user-scoped data.
- Emulator tests for rules.
- Error/loading/empty state pass.
- Accessibility pass.
- Responsive visual QA.
- Basic backup/export consideration.
- Documentation update.

Acceptance criteria:

- Users cannot read/write another user's data.
- Today Board, Calendar, Stats, Settings have loading/empty/error states.
- Keyboard navigation works for core flows.
- Mobile web layout is usable.
- README explains setup, test, build, Firebase configuration, and known limitations.

Verification:

- Firebase security rules tests.
- Build/test/lint pass.
- Manual smoke test checklist.
- Responsive screenshots.

## 4. Suggested first implementation slice

The first coding slice should be intentionally small:

1. Scaffold the web app under `DailyFlow/`.
2. Add app shell and placeholder routes.
3. Add design tokens and a mock-data Today Board.
4. Add achievement-rate pure function with tests.

Why this slice first:

- It produces visible progress quickly.
- It validates the core Today Board layout before Firebase complexity.
- The achievement-rate rule is central and can be locked with tests early.
- It keeps the first commit reviewable.

## 5. Test strategy by layer

### Unit tests

- Achievement-rate formula.
- Task status transitions.
- Carry-over date logic.
- Recurrence duplicate prevention.
- Weekly/monthly average aggregation.
- Calendar date-range helpers.

### Integration tests

- Firestore task CRUD using emulator.
- Auth bootstrap logic where practical.
- Stats recomputation path.
- Security rules.

### UI/smoke tests

- Today Board loads.
- Create task.
- Move task between statuses.
- Complete task and see count/rate update.
- Carry task to another date.
- Create calendar event.
- Switch calendar day/week/month views.

### Manual QA

- Offline edit and online sync.
- Browser push permission and delivery.
- Mobile responsive layout.
- Keyboard/focus behavior.

## 6. Main risks and mitigations

### Risk: MVP becomes too broad

Mitigation:

- Keep Today Board as the release gate.
- Implement Calendar/Stats only to agreed MVP depth.
- Defer collaboration and native apps.

### Risk: Firestore statistics become expensive or inconsistent

Mitigation:

- Use daily/weekly/monthly summary documents.
- Test aggregation functions with fixtures.
- Keep client optimistic stats separate from canonical stats.

### Risk: Offline sync behavior is confusing

Mitigation:

- Show pending sync state.
- Avoid transaction-dependent offline edits.
- Document last-modified-wins in UI/help text where needed.

### Risk: Browser push is platform/browser sensitive

Mitigation:

- Treat browser push as a dedicated phase.
- Provide clear permission states.
- Use test notifications before relying on scheduled reminders.

### Risk: Native app future conflicts with web MVP decisions

Mitigation:

- Keep product concepts and Firestore model platform-neutral.
- Avoid web-only data assumptions.
- Keep notification subscriptions platform-aware from the start.

## 7. Commit plan

Recommended commit units:

1. `chore: scaffold DailyFlow web app`
2. `feat: add DailyFlow app shell and design tokens`
3. `feat: add mock Today Board`
4. `test: cover achievement rate calculation`
5. `feat: add Firebase auth bootstrap`
6. `feat: add Firestore task repository`
7. `feat: add task status Kanban interactions`
8. `feat: add offline task sync indicators`
9. `feat: add carry-over and recurring routines`
10. `feat: add calendar MVP`
11. `feat: add achievement statistics`
12. `feat: add browser push reminders`
13. `test: add security rules and emulator coverage`
14. `docs: update DailyFlow setup and MVP notes`

Each commit should leave the project buildable and testable.

## 8. Definition of MVP done

MVP is done when:

- A user can sign in.
- A user can manage today's tasks on a category-first daily Kanban board.
- Counts and achievement rate update automatically.
- On-hold tasks and events are excluded from achievement.
- A user can carry tasks to another date.
- Daily recurring tasks generate without duplicates.
- Calendar week/day/month views exist with Korean holidays.
- Events can be created and edited separately from tasks.
- Daily, weekly, and monthly achievement stats are visible.
- Browser push reminders work in supported browsers.
- Tasks can be viewed/edited offline and sync online.
- Security rules prevent cross-user data access.
- Build, tests, and core smoke checks pass.
