# Design

## Source of truth

- Status: Active
- Last refreshed: 2026-06-24
- Primary product surfaces:
  - Today Board: primary home surface for daily planning, task state management, carry-over, recurring tasks, and daily achievement rate.
  - Calendar: week-first schedule and productivity view with day/week/month modes and South Korean holidays.
  - Statistics: daily achievement-rate-first analytics, plus weekly and monthly averages.
  - Settings: categories, recurrence, notifications, account, and future collaboration preferences.
- Evidence reviewed:
  - `README.md`: repository is a DailyCoding learning/workspace repository.
  - `DEPENDENCY_MAINTENANCE.md`: obsolete React Native examples were removed; future native work should not restore old dependency graphs unchanged.
  - `React/todo/package.json`: existing learning todo app uses Vite + React 18, but current product direction is broader than that demo.
  - `.omx/context/todo-app-planning-20260622T223859Z.md`: deep interview context and product requirements.
  - `src/features/today/TodayBoardPlaceholder.tsx` and `src/styles.css`: first implementation was functional but visually too dashboard-like; 2026-06-24 pass shifts Today toward an Apple Reminders/Calendar-inspired surface.

## Brand

- Personality:
  - Calm, organized, personal, reliable, and native-app-like.
  - Inspired by Apple Calendar and Apple Reminders: restrained, readable, spacious, and polished.
- Trust signals:
  - Clear data counts and formulas.
  - Predictable state transitions.
  - Visible sync/account status once implemented.
  - Respectful notification controls.
- Avoid:
  - Busy admin-dashboard aesthetics.
  - Overly colorful or gamified screens.
  - Notion-clone visual language.
  - Hiding important counts behind multiple clicks.

## Product goals

- Goals:
  - Replace manual Notion-based daily checklist counting.
  - Make today's planned work, progress, and achievement rate visible at a glance.
  - Support configurable categories rather than fixed groups.
  - Support task states: planned, in progress, on hold, completed.
  - Exclude on-hold tasks from daily achievement-rate denominator.
  - Support carry-over to another date, counting the task toward the destination date.
  - Auto-generate recurring routines.
  - Support calendar event management with alerts.
  - Keep calendar events separate from task achievement-rate calculations.
  - Support cloud sync across devices via social-login-backed accounts.
  - Support offline viewing/editing for tasks, then sync changes when online.
  - Leave room for future native iOS/Android apps and future sharing/collaboration.
- Non-goals:
  - Public/team collaboration in MVP.
  - Email, mobile push, Telegram, or other third-party notification channels in MVP.
  - Deep analytics before daily achievement-rate basics are excellent.
  - Restoring old React Native study projects as the native app base.
- Success signals:
  - Opening the app immediately answers: “What is today’s plan and how much have I completed?”
  - Adding or completing a task automatically updates counts and percentage.
  - Carry-over and recurring tasks require little manual bookkeeping.
  - The UI feels clean enough for daily use, not tiring or cluttered.

## Personas and jobs

- Primary personas:
  - Individual user managing personal life, work, self-development, and daily routines.
- User jobs:
  - Plan today's work by category.
  - Track task status through planned, in progress, on hold, and completed.
  - See daily achievement rate without manual calculation.
  - Move unfinished work to another date.
  - Automatically receive daily recurring routine tasks.
  - Manage weekly schedule events and reminders.
  - Review daily performance across dates.
- Key contexts of use:
  - Morning planning.
  - Midday progress checks.
  - End-of-day review.
  - Weekly schedule planning.
  - Multi-device use through a synced account.

## Information architecture

- Primary navigation:
  - Today
  - Calendar
  - Stats
  - Settings
- Core routes/screens:
  - Today Board
  - Task detail/create/edit
  - Calendar day/week/month
  - Event detail/create/edit
  - Daily statistics overview
  - Weekly/monthly achievement averages
  - Category settings
  - Recurring routine settings
  - Notification settings
  - Account/login
- Content hierarchy:
  - Today Board:
    1. Date and day context
    2. Daily achievement summary
    3. Primary actions: add task, add event, carry-over review
    4. Status-first Kanban lanes: planned, in progress, on hold, completed
    5. Category filters/chips/colors as secondary organization
    6. Today's schedule summary
  - Calendar:
    1. View selector: day/week/month
    2. Weekly summary: task achievement rate, completed/planned task count, and event count
    3. 00:00–24:00 time grid for week view
    4. Events placed in hourly slots with quick slot-based event creation
    5. Horizontal navigation with mouse side wheel, trackpad horizontal scroll, and vertical wheel translated to horizontal movement inside the timetable
    6. Task distribution and achievement overlays
    7. South Korean holidays

## Design principles

- Principle 1: Daily clarity before feature density.
  - The Today Board must make plan, progress, and completion rate obvious without scanning many panels.
- Principle 2: Automatic accounting must be visible and trustworthy.
  - Counts, denominators, exclusions, and carry-over behavior should be understandable.
- Principle 3: Native-feeling restraint.
  - Use spacing, typography, subtle surfaces, and semantic color rather than heavy decoration.
  - Avoid dense metric grids as the first impression; prefer one clear daily summary plus compact supporting metrics.
- Principle 4: Future expansion without MVP overload.
  - Leave conceptual room for native apps and collaboration, but do not crowd the MVP UI with those features.
- Tradeoffs:
  - Detailed task creation is preferred over ultra-fast one-line capture.
  - Today Board is prioritized over advanced statistics.
  - Browser push is prioritized first, while other notification channels remain future extensions.

## Visual language

- Color:
  - Base: warm or cool near-white backgrounds, soft gray dividers, high-contrast text.
  - Accent: a restrained primary blue inspired by Apple system blue.
  - Status colors:
    - Planned: neutral gray/blue.
    - In progress: blue or amber.
    - On hold: muted gray/purple; visually excluded from achievement emphasis.
    - Completed: green.
  - Category colors should be configurable but softly rendered as dots, chips, or side accents rather than full-color blocks.
  - Priority should be shown with restrained indicators: high, normal, low. High can use a warm accent; normal should be quiet; low should be muted.
- Typography:
  - System font stack preferred for native-like feel.
  - Strong numeric hierarchy for daily counts and percentage.
  - Avoid tiny labels for critical metrics.
- Spacing/layout rhythm:
  - Spacious, card-based layout with consistent 8px-derived rhythm.
  - The Today Board should not feel like a dense spreadsheet.
- Shape/radius/elevation:
  - Rounded cards and controls with subtle shadows or hairline borders.
  - Prefer depth restraint over heavy elevation.
- Motion:
  - Subtle transitions for status movement, completion, and view switching.
  - No distracting gamified animations in MVP.
- Imagery/iconography:
  - Minimal line icons where useful.
  - Icons support labels; they should not replace important text.

## Components

- Existing components to reuse:
  - DailyFlow now has initial shared UI primitives: `Button`, `Card`, `Badge`, `PageHeader`, and `PlaceholderPanel`.
  - Existing `React/todo` can be treated as reference code only, not a design source of truth.
- New/changed components:
  - App shell/navigation.
  - Today summary header.
  - Achievement ring/progress indicator.
  - Count cards.
  - Task card.
  - Status lane/column.
  - Category chip/filter.
  - Task detail form, including priority: high / normal / low.
  - Carry-over drawer/dialog.
  - Recurring routine marker.
  - Calendar grid: day/week/month.
  - Event card/block.
  - Holiday marker.
  - Notification permission prompt.
- Variants and states:
  - Task: planned, in progress, on hold, completed, recurring, carried-over, has reminder, high/normal/low priority.
  - Event: timed, all-day, recurring/future, reminder enabled; excluded from achievement-rate calculation.
  - Calendar day: today, selected, holiday, high/medium/low achievement.
- Token/component ownership:
  - Future implementation should centralize colors, spacing, radius, typography, and status/category tokens.

## Accessibility

- Target standard:
  - Aim for WCAG 2.2 AA for contrast, keyboard access, labels, and focus visibility.
- Keyboard/focus behavior:
  - Full keyboard operation for navigation, task creation, status movement, and calendar view changes.
  - Visible focus rings matching the restrained Apple-like style.
- Contrast/readability:
  - Do not rely on color alone for task status or achievement.
  - Numeric summary values must remain readable on mobile and desktop.
- Screen-reader semantics:
  - Status lanes should expose meaningful labels and task counts.
  - Achievement rate should be announced as text, not only a chart.
- Reduced motion and sensory considerations:
  - Respect reduced-motion preference.
  - Avoid flashing or high-intensity animations.

## Responsive behavior

- Supported breakpoints/devices:
  - Desktop web.
  - Tablet web.
  - Mobile web.
  - Future native iOS/Android should be considered conceptually, but not implemented from this design doc yet.
- Layout adaptations:
  - Desktop Today Board: summary header plus configurable category lanes for the selected date; task status is handled inside each card and no longer defines the main board columns.
  - Tablet: fewer columns or horizontally scrollable lanes.
  - Mobile: segmented status tabs or stacked lanes; summary remains sticky or near top.
  - Calendar desktop/tablet: week view is primary and should open on the current week, show a top achievement summary followed by a 00:00–24:00 hourly schedule grid, keep the time axis fixed, and let horizontal/side-wheel scrolling move only the date columns.
  - Calendar mobile: day and agenda-style views may be more usable than dense month grids.
- Touch/hover differences:
  - Do not require hover for core actions.
  - Touch targets should be comfortably sized.

## Interaction states

- Loading:
  - Skeleton cards for summary metrics and task lanes.
- Empty:
  - Today Board empty state should encourage adding a task or generating recurring routines.
  - Calendar empty state should still show date grid and holidays.
- Error:
  - Sync, login, conflict, and notification-permission errors should be explicit and recoverable.
- Success:
  - Completing a task should update counts immediately with subtle visual feedback.
  - Carrying a task over should remove it from the current day's active lanes and count it on the destination date.
- Disabled:
  - Disabled actions must explain why when relevant, especially notification permission or sync-dependent features.
- Offline/slow network, if applicable:
  - Users must be able to view and edit tasks offline.
  - Offline changes should queue locally and sync when the device returns online.
  - UI should clearly show unsynced changes and sync/conflict status.
  - The Today Board shows online/offline state, pending local task changes, and last synced time at task-card level.
- Conflict resolution:
  - Default rule: last modified version wins.
  - Show conflict/recovery UI only when automatic resolution is risky or fails.
  - Preserve enough local metadata to explain sync state when needed.

## Content voice

- Tone:
  - Calm, direct, encouraging, and not overly playful.
- Terminology:
  - 할 일: achievement-tracked task.
  - 일정: calendar event, separate from task.
  - 예정 / 진행중 / 보류 / 완료: task states.
  - 이월: moving unfinished work to a different date.
  - 달성률: task-only metric; completed divided by planned + in-progress + completed; on-hold and calendar events excluded.
- Microcopy rules:
  - Explain calculations plainly.
  - Use action labels that match the user’s mental model: “이월하기”, “보류로 이동”, “완료 처리”.
  - Avoid vague labels like “처리” when a specific state change is intended.

## Implementation constraints

- Framework/styling system:
  - Initial web app scaffold: Vite + React + TypeScript.
  - Styling baseline: CSS design tokens and shared UI primitives under `src/components/ui`.
  - BaaS decision: Firebase for initial implementation. See `docs/decisions/0001-baas-firebase.md`.
  - Firestore data model draft: `docs/technical/firestore-data-model.md`.
- Design-token constraints:
  - Future implementation should define semantic tokens for status, category, calendar, achievement, sync, and conflict states.
- Performance constraints:
  - Today Board must load quickly because it is the daily entry point.
  - Calendar should handle day/week/month switching without feeling heavy.
  - Statistics should calculate daily achievement plus weekly and monthly averages clearly and consistently.
- Compatibility constraints:
  - Social login is primary, likely Apple/Google first.
  - Browser push is the MVP notification channel.
  - Future native iOS/Android apps should be able to share product concepts and backend data model.
- Test/screenshot expectations:
  - Future UI work should include responsive screenshots for Today Board and Calendar.
  - Acceptance tests should cover achievement-rate calculation and task state transitions.

## Open questions

- [x] Today Board default grouping: date-first category Kanban. Each date has configurable category lanes such as 오늘의 생활, 오늘의 할 일, 오늘의 자기 계발, 오늘의 업무; task status is card metadata/actions, not the primary board grouping. / owner: user / corrected: 2026-06-24.
- [x] Task priority levels: high / normal / low. / owner: user / resolved: 2026-06-23.
- [x] Calendar events do not influence daily achievement rate; only tasks are counted. / owner: user / resolved: 2026-06-23.
- [x] Statistics MVP includes daily achievement, weekly average, and monthly average. / owner: user / resolved: 2026-06-23.
- [x] BaaS choice: Firebase for initial implementation. See `docs/decisions/0001-baas-firebase.md`. / owner: technical planning / resolved: 2026-06-23.
- [x] Offline behavior: users can view and edit tasks offline; changes sync when back online. / owner: user / resolved: 2026-06-23.
- [x] Offline sync conflict default: last modified version wins; show conflict UI only when needed. / owner: user / resolved: 2026-06-23.
