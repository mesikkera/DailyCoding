# DailyFlow

DailyFlow is a personal productivity app for managing daily tasks, routines, calendar events, reminders, and achievement rates.

## Current status

Phase 1 product shell complete: Vite + React + TypeScript app shell, design tokens, shared UI primitives, and placeholder product surfaces.

## Key documents

- `DESIGN.md` — product, UX, visual design, accessibility, and interaction source of truth.
- `docs/planning/interview-context.md` — interview/context log that led to the current requirements.
- `docs/planning/mvp-development-plan.md` — phased MVP implementation plan and acceptance criteria.
- `docs/decisions/0001-baas-firebase.md` — BaaS decision record: Firebase selected over Supabase for the initial implementation.
- `docs/technical/firestore-data-model.md` — draft Firestore data model.

## Product direction

- Today Board first.
- Status-first Kanban: planned, in progress, on hold, completed.
- Configurable categories.
- Automatic daily achievement rate.
- Calendar events separate from tasks.
- Weekly calendar as default, with day/month views.
- Offline task viewing/editing with sync when online.
- Browser push first; native mobile apps later.

## Development

```bash
npm install
npm run dev
```

Useful commands:

```bash
npm run build
npm run test
npm run lint
npm run format
```

## Firebase configuration

Copy `.env.example` to `.env` and fill in the Firebase web app values when a Firebase project is available.

```bash
cp .env.example .env
```

The app shell does not require Firebase credentials yet, but feature implementation will use Firebase Auth, Firestore, and FCM per `docs/decisions/0001-baas-firebase.md`.
