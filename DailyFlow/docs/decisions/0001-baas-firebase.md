# ADR 0001: Use Firebase as the initial BaaS

- Status: Accepted
- Date: 2026-06-23

## Context

The product is a personal productivity ToDo/calendar app with these backend-relevant requirements:

- Social-login-centered account system.
- Multi-device sync.
- Offline task viewing/editing.
- Sync local changes when back online.
- Default conflict resolution: last modified version wins.
- Browser push in MVP.
- Later native iOS/Android apps and mobile push.
- Calendar events, tasks, recurring routines, and daily/weekly/monthly achievement statistics.

## Options considered

### Firebase

Strengths for this product:

- Firebase Auth supports web, iOS, Android, and common federated identity providers such as Google and Apple.
- Cloud Firestore has first-party offline persistence for Android, Apple, and web apps.
- Firestore syncs local changes back to the backend when the device returns online.
- Firestore's documented conflict behavior for multiple writes to the same document is last-write-wins, matching the product decision.
- Firebase Cloud Messaging supports iOS, Android, and web push, matching the MVP browser push and future mobile push path.
- Firebase Hosting, Cloud Functions, Emulator Suite, Crashlytics, Performance Monitoring, and Test Lab are useful for later web/native operation.

Tradeoffs:

- Firestore is NoSQL/document-oriented, so relational reporting must be modeled carefully.
- Complex calendar/statistics queries may require denormalized summary documents or server-side aggregation.
- Vendor lock-in is higher than a Postgres-first stack.

### Supabase

Strengths for this product:

- PostgreSQL-first model is attractive for tasks, events, recurrence, statistics, and future collaboration.
- Supabase Auth supports social providers including Apple and Google.
- Row Level Security maps well to future sharing/collaboration permissions.
- Realtime and Edge Functions can support live updates and backend workflows.
- Open-source posture and SQL portability are strong advantages.

Tradeoffs:

- Supabase does not provide the same first-party offline persistence/sync client behavior as Firestore for web/iOS/Android in the official core docs reviewed.
- Offline editing, local queueing, conflict handling, and re-sync would require a custom local-first layer or an additional sync product.
- Push notification architecture would need more custom integration than Firebase Cloud Messaging.

## Decision

Use Firebase as the initial BaaS:

- Firebase Authentication for social login.
- Cloud Firestore for tasks, events, categories, recurrence templates, notification subscriptions, and aggregated stats documents.
- Firebase Cloud Messaging for browser push first and native mobile push later.
- Cloud Functions or scheduled functions for reminder dispatch, recurrence materialization, and statistics aggregation.
- Firebase Hosting or another compatible web host for the web app.

## Consequences

- MVP backend aligns directly with the strongest requirements: offline task editing, sync, last-write-wins behavior, browser push, and future native push.
- Data modeling should be designed around Firestore collections/documents, not normalized SQL tables.
- Statistics should likely use precomputed daily/weekly/monthly summary documents to avoid expensive client-side scans.
- If future reporting/collaboration becomes highly relational, reconsider Supabase/Postgres or analytics export as a later architecture decision.

## References reviewed

- Firebase Firestore offline persistence: https://firebase.google.com/docs/firestore/manage-data/enable-offline
- Firebase Authentication: https://firebase.google.com/docs/auth
- Firebase Cloud Messaging: https://firebase.google.com/docs/cloud-messaging
- Firebase pricing: https://firebase.google.com/pricing
- Supabase Auth: https://supabase.com/docs/guides/auth
- Supabase Realtime: https://supabase.com/docs/guides/realtime
- Supabase Edge Functions: https://supabase.com/docs/guides/functions
- Supabase Database overview: https://supabase.com/docs/guides/database/overview
