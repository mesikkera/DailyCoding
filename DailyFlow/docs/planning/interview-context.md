# Deep Interview Context Snapshot: ToDo App Planning

## Task statement

User wants to build a web-based ToDo app, with enough future direction that it could later ship as iPhone and Android apps. User asked to first have a deep conversation and make a plan.

## Desired outcome

A clarified product/technical plan for a ToDo app before implementation.

## Stated solution

Start with a web app; keep future iOS/Android release in mind.

## Probable intent hypothesis

User likely wants a practical project roadmap balancing MVP scope, product differentiation, architecture choices, and future cross-platform expansion.

## Known facts / evidence

- Repository is `DailyCoding`, described as "Daily Coding for Fun".
- Existing `React/todo` project exists and is currently Vite + React 18 + Redux-era dependencies.
- Older React Native study projects were explicitly removed earlier because they were obsolete and vulnerability-heavy.
- Dependency maintenance notes recommend restoring old native examples only from history and migrating as fresh native projects if needed.

## Constraints

- No implementation requested yet.
- Avoid reintroducing old React Native dependency graph.
- Future mobile path matters, but first deliverable is planning conversation.

## Unknowns / open questions

- Primary purpose: personal productivity, portfolio, learning, or real public service.
- Target users and differentiating value.
- MVP feature boundaries.
- Account/sync/offline requirements.
- Preferred stack and hosting constraints.
- Whether to reuse `React/todo` or create a new app/package.

## Decision-boundary unknowns

- Cross-platform strategy: web-first PWA, React Native later, Expo later, or shared backend plus separate clients.
- Data model complexity: simple local tasks vs authenticated cloud sync.
- Product scope: minimalist ToDo vs calendar/habits/projects/collaboration.

## Likely codebase touchpoints

- `React/todo/` may be reference material or migration base.
- New project directory may be cleaner if the goal is production-style app.
- `DEPENDENCY_MAINTENANCE.md` should remain consistent if new dependency strategy is chosen later.

## Relevant repo docs/rules/context inspected

- `README.md`
- `DEPENDENCY_MAINTENANCE.md`
- `React/todo/package.json`
- `React/todo` file listing

## Terminology / doc-code conflicts found

None yet. Existing `React/todo` is a learning/demo project, while user appears to want a more deliberate future-ready app.

## Prompt-safe initial-context summary status

Not needed; no external pasted corpus beyond the user request and repo docs.

## Interview log

### Round 1 — Purpose

Question: 이 ToDo 앱의 1순위 목적은 무엇인가?
Answer: 개인용 생산성 도구.

### Updated interpretation

The app should optimize for the user's own daily productivity and long-term usability before public-market differentiation. Planning should prioritize personal workflow fit, low-friction capture, reliable reminders/sync/offline behavior, and future portability over social/collaboration features.

### Round 2 — Current pain

Question: 지금 쓰고 있는 ToDo/메모/일정 관리 방식에서 가장 불편한 점 하나는 무엇인가?
Answer summary:

- Currently uses Notion with category checklists.
- Counts are not automatically updated when adding new tasks or completing tasks.
- Current categories: "오늘의 생활", "오늘의 할 일", "오늘의 자기 계발", "오늘의 업무".
- Categories should be user-configurable, not fixed.
- Daily total planned tasks and achievement percentage are manually calculated.
- Uses a daily Kanban-board-like structure.
- Daily achievement rate is hard to see at a glance.
- Overall statistics are also hard to check.

### Updated requirements inferred from pain points

- Automatic counting of planned/completed tasks.
- Configurable categories/groups.
- Daily dashboard with total planned/completed and completion percentage.
- Daily board/calendar-like view with at-a-glance achievement.
- Statistics across days/categories.
- Preserve the user's current mental model: daily planning + category checklists + completion tracking.

### Round 3 — Carry-over model

Question: 하나의 일은 특정 하루에만 속하는 일인가, 아니면 오늘 못 끝내면 이월되는 구조가 필요한가?
Answer: Uncompleted tasks should be carryable to the next day or another day, and this behavior should be configurable.

### Updated requirements inferred

- Tasks have a scheduled/planned date.
- Uncompleted tasks can be moved/carry-over to another date.
- Carry-over behavior should be configurable rather than hardcoded.
- Need distinguish planned-for-day vs originally-created-on-day vs carried-over-from-previous-day for meaningful statistics.

### Round 4 — Task status model

Question: 일의 상태는 단순 미완료/완료인가, 아니면 예정/진행중/보류/완료 같은 단계가 필요한가?
Answer: 예정 / 진행중 / 보류 / 완료 단계가 필요하다.

### Updated requirements inferred

- Task status enum should include: planned, in_progress, on_hold, completed.
- Completion count and achievement rate should probably count only `completed` as achieved.
- Kanban view is naturally supported by these statuses.
- Need define whether `on_hold` contributes to planned denominator or is excluded; unresolved.

### Round 5 — Primary view

Question: 가장 자주 보고 싶은 화면은 오늘 하루 보드인가, 주간/월간 달성률 캘린더인가?
Answer: 오늘 하루 보드가 우선.

### Updated requirements inferred

- MVP should optimize the Today Board first.
- Weekly/monthly calendar/statistics can be secondary but should be supported by data design.
- First user journey: open app -> see today's categories, status columns, counts, completion rate, and carry-over items.

### Round 6 — Recurring tasks

Question: 매일 반복되는 일도 자동으로 생성되어야 하는가?
Answer: Yes.

### Updated requirements inferred

- App needs recurring task templates/rules.
- Daily board can be generated/populated from recurring templates.
- Need avoid duplicate generation when opening the same day multiple times.
- Recurrence may start simple with daily routines, later extend to weekdays/custom schedules.

### Round 7 — Multi-device sync and calendar

Question: 처음부터 여러 기기에서 같은 데이터를 봐야 하는가, 아니면 MVP는 한 기기/브라우저 저장으로 시작해도 되는가?
Answer: 여러 기기에서 같은 데이터를 봐야 하고, Mac Calendar와 동일한 기능의 캘린더도 포함되면 좋겠다.

### Updated requirements inferred

- MVP likely needs account/auth and cloud persistence from the beginning.
- Local-only browser storage is insufficient for the intended product.
- Cross-device sync should be a core architectural requirement.
- Calendar becomes a significant product surface, not just a stats view.
- Need clarify whether “Mac Calendar-like” means schedule events, reminders, calendar grid UX, recurring events, alerts, external calendar integration, or all of these.

### Round 8 — Calendar purpose

Question: 캘린더는 일정 이벤트 관리가 목적일까, ToDo 달성률/할 일 배치 현황을 날짜별로 보는 화면이 목적일까?
Answer: 둘 다. 일정 이벤트 관리는 주 단위로 하고 있고 알람 요소가 필요하다. 일/주/월 선택지가 있으면 좋고, 달성률과 할 일 배치 현황을 볼 수 있으면 좋다.

### Updated requirements inferred

- Calendar needs event management and productivity analytics overlays.
- Views: day, week, month.
- Weekly event planning is important.
- Alerts/reminders are needed.
- Calendar should show task distribution and completion rates by date.
- Need design separate but connected entities: tasks vs calendar events vs recurring routines.

### Round 9 — Notification channels

Question: 알림은 앱 안/브라우저 푸시 정도면 충분한가, 아니면 이메일·모바일 푸시까지 처음부터 고려해야 하는가?
Answer: 이메일 / 모바일 푸시 / 텔레그램 등 제3자 앱 푸시도 지원하면 좋겠다.

### Updated requirements inferred

- Notification architecture should support multiple delivery channels.
- Channels of interest: email, mobile push, Telegram/third-party app push, likely in-app/browser push.
- MVP should probably define a minimal first channel while designing extensible notification delivery.
- Need scheduled jobs / background worker capability for reliable reminders.
- Future mobile release will require native push infrastructure.

### Round 10 — MVP notification channel

Question: 1차 MVP에서 반드시 동작해야 하는 알림 채널 하나는 무엇인가?
Answer: 브라우저 푸시.

### Updated requirements inferred

- MVP notification channel: browser push/web push.
- Architecture should allow later email, mobile push, Telegram/third-party channels.
- Web app should likely be a PWA or at least support service worker/push subscription.

### Round 11 — Primary statistic

Question: 통계에서 가장 중요하게 보고 싶은 지표는 일별 달성률, 카테고리별 달성률, 연속 달성/습관 추세 중 무엇인가?
Answer: 일별 달성률.

### Updated requirements inferred

- Daily completion/achievement rate is the primary analytics metric.
- Category-level and habit streaks can be secondary/future.
- Calendar and dashboard should prominently display daily achievement.
- Need define denominator and exclusions for statuses like on_hold.

### Round 12 — On-hold in achievement rate

Question: `보류` 상태의 일은 그날 달성률 계산에서 분모에 포함해야 할까, 제외해야 할까?
Answer: 제외.

### Updated requirements inferred

- Daily achievement denominator excludes `on_hold` tasks.
- Candidate formula: completed / (planned + in_progress + completed), excluding on_hold.
- Need handle carried-over tasks in denominator once assigned to a date.

### Round 13 — Carry-over statistics

Question: 이월된 일은 옮겨진 날짜의 달성률에 포함해야 하나, 원래 계획했던 날짜의 미완료로 남아야 하나?
Answer: 옮겨진 날짜의 달성률에 포함.

### Updated requirements inferred

- A task contributes to the daily achievement denominator for its current scheduled date.
- Moving a task to another date effectively reassigns its achievement accounting.
- Original-date history may still be useful for audit/insight but is not the primary daily rate calculation.

### Round 14 — Task input style

Question: 할 일을 추가할 때 가장 중요한 입력 방식은 빠른 한 줄 입력인가, 자세한 설정 입력인가?
Answer: 자세히 설정 입력.

### Updated requirements inferred

- Task creation form should support category, date, status, reminder, recurrence, and possibly priority/notes from the start.
- Quick-add can be secondary/future, not the primary MVP input mode.
- UX should optimize correctness/organization over ultra-fast capture.

### Round 15 — Events vs tasks

Question: 캘린더의 일정 이벤트와 할 일은 완전히 다른 항목이어야 하나, 할 일에 시간대를 지정하면 캘린더 일정처럼 보이는 구조가 좋을까?
Answer: 완전히 다른 항목.

### Updated requirements inferred

- Data model should separate Task and CalendarEvent entities.
- Calendar can display both, but they have different semantics.
- Tasks drive productivity completion metrics; events drive time scheduling/reminders.
- Need decide whether events affect daily achievement rate; likely no, unless later specified.

### Round 16 — Collaboration scope

Question: 처음에는 본인 혼자만 쓰는 1인용이면 충분한가, 아니면 나중의 공유/협업도 설계에 넣어야 하나?
Answer: 처음에는 나 혼자, 나중에 공유/협업.

### Updated requirements inferred

- MVP can be single-user workspace after login.
- Data model should not block future multi-user sharing/collaboration.
- Future concepts may include workspace, owner_id, shared access, collaborators, permissions.
- Avoid overbuilding collaboration UI in MVP.

### Round 17 — Tech preference and design taste

Question: 기술 스택 선호가 있는가?
Answer: 따로 없다. 디자인은 최신 스타일로 예쁘면 좋겠다. 깔끔하면서도 가독성이 좋고, 색상 조합이 좋은 것을 선호한다.

### Updated requirements inferred

- Technology stack can be chosen based on product needs and future mobile path.
- UI/UX quality is a material requirement, not an afterthought.
- Design direction: modern, clean, readable, tasteful color palette.
- Need later define visual references/style system to reduce subjectivity.

### Round 18 — Visual style

Question: 디자인 분위기는 Apple 캘린더/리마인더처럼 절제된 스타일과 Linear/Notion처럼 미니멀 생산성 도구 중 어느 쪽인가?
Answer: Apple 캘린더 / 리마인더 스타일.

### Updated requirements inferred

- Visual direction: Apple Calendar/Reminders-inspired, restrained, clean, readable.
- Likely preferences: soft neutral backgrounds, semantic accent colors, high spacing discipline, native-app-like interactions.
- Web app should feel polished and native-like, not like a generic admin dashboard.

### Round 19 — MVP must-have screen

Question: 1차 MVP에서 꼭 있어야 하는 화면 하나만 고르면 오늘 보드인가, 캘린더인가?
Answer: 오늘 보드.

### Updated requirements inferred

- MVP success should be judged primarily by Today Board usefulness.
- Calendar is important but can be phased behind Today Board if scope requires.
- Today Board should include status columns, category grouping/filtering, daily counts, achievement percentage, carry-over handling, recurring tasks, and browser push reminders.

### Round 20 — Calendar MVP scope

Question: MVP의 캘린더는 처음부터 일/주/월 전체가 필요한가, 아니면 주간 캘린더부터 시작해도 되는가?
Answer: 주간 캘린더가 기본 / 일, 월 캘린더도 지원 / 대한민국 공휴일 포함.

### Updated requirements inferred

- Default calendar view: week.
- Calendar must also support day and month views.
- South Korean holidays should be displayed.
- Need holiday data source strategy; can be static yearly data, API, or library later.
- Calendar scope is larger than a minimal placeholder; still Today Board remains primary MVP screen.

### Round 21 — Backend/service strategy

Question: 직접 서버/DB 운영 vs Supabase/Firebase 같은 BaaS 활용 중 어느 쪽인가?
Answer: Supabase/Firebase 등 사용.

### Updated requirements inferred

- Prefer BaaS to reduce backend/ops burden.
- Architecture should use managed auth, database, storage if needed, and serverless/background jobs where appropriate.
- Need compare Supabase vs Firebase later for auth, realtime sync, scheduled notifications, web push, future mobile support, and developer experience.

### Round 22 — Login strategy

Question: 로그인은 이메일/비밀번호 중심인가, Apple/Google 소셜 로그인 중심인가?
Answer: 소셜 로그인 중심.

### Updated requirements inferred

- Auth UX should prioritize social login.
- Likely providers: Apple and Google first, especially because future iOS/Android support matters.
- Email/password can be optional fallback rather than primary.
- BaaS choice should support social auth well across web and mobile.

### Round 23 — Mobile strategy

Question: 모바일은 PWA로 충분한가, App Store/Play Store 네이티브 앱까지 목표인가?
Answer: 웹앱/PWA.

### Updated requirements inferred

- Cross-platform strategy: responsive web app + PWA, not native app in the first long-term plan.
- Browser push + installable PWA should be aligned.
- Future iPhone/Android usage can be via PWA install, avoiding React Native/Expo initially.
- Tech choices should prioritize excellent mobile web UX and PWA capabilities.

### Round 24 — Planning output and mobile correction

Question: 계획은 제품 요구사항 중심으로 정리할까, 기술/DB/개발순서까지 포함한 실행 계획으로 정리할까?
Answer: 모바일은 네이티브 앱으로 변경하고, 제품 요구사항 중심으로 우선 깊게 정리.

### Updated requirements inferred

- Mobile strategy updated from PWA to native app later.
- Current output should prioritize product requirements, not implementation details.
- Technical stack/DB/development sequencing can be deferred to a later planning phase.
