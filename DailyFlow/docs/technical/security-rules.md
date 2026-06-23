# Firestore Security Rules Draft

- Status: Draft
- Date: 2026-06-23
- Scope: DailyFlow MVP user-scoped data

## MVP rule

All MVP data lives below `users/{userId}`. Reads and writes are allowed only when `request.auth.uid == userId`.

Covered collections:

- `profile` / root user document
- `settings`
- `categories`
- `tasks`
- `events`
- `recurrenceRules`
- `notificationSubscriptions`
- `statsDaily`, `statsWeekly`, `statsMonthly`
- `syncMetadata`

## Not yet covered

- Collaboration/workspaces: out of MVP scope.
- Field-level validation: should be added before public beta.
- Emulator rule tests: planned hardening task once Firebase emulator config is added.
