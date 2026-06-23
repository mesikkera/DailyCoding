import { calculateAchievementSummary, type TaskStatus } from './achievement';

interface MockTask {
  id: string;
  title: string;
  category: string;
  priority: 'high' | 'normal' | 'low';
  status: TaskStatus;
}

const mockTasks: MockTask[] = [
  {
    id: 'task-1',
    title: '아침 루틴 정리',
    category: '오늘의 생활',
    priority: 'normal',
    status: 'planned',
  },
  {
    id: 'task-2',
    title: 'DailyFlow 설계 문서 검토',
    category: '오늘의 업무',
    priority: 'high',
    status: 'in_progress',
  },
  {
    id: 'task-3',
    title: '운동 30분',
    category: '오늘의 자기 계발',
    priority: 'normal',
    status: 'completed',
  },
  {
    id: 'task-4',
    title: '장기 보류 아이디어 정리',
    category: '오늘의 할 일',
    priority: 'low',
    status: 'on_hold',
  },
];

const lanes: Array<{ label: string; status: TaskStatus }> = [
  { label: '예정', status: 'planned' },
  { label: '진행중', status: 'in_progress' },
  { label: '보류', status: 'on_hold' },
  { label: '완료', status: 'completed' },
];

export function TodayBoardPlaceholder() {
  const summary = calculateAchievementSummary(mockTasks);
  const percentage = Math.round(summary.achievementRate * 100);

  return (
    <section className="today-board" aria-labelledby="today-heading">
      <header className="today-header">
        <div>
          <p className="eyebrow">Today Board</p>
          <h1 id="today-heading">오늘의 흐름</h1>
          <p className="muted">
            상태 중심 칸반으로 오늘의 계획과 달성률을 봅니다.
          </p>
        </div>
        <button className="primary-action" type="button">
          + 할 일 추가
        </button>
      </header>

      <div className="summary-grid" aria-label="오늘 요약">
        <article className="summary-card hero-card">
          <span>달성률</span>
          <strong>{percentage}%</strong>
          <small>
            완료 {summary.completedCount} / 대상 {summary.denominatorCount}
          </small>
        </article>
        <SummaryCard label="예정" value={summary.plannedCount} />
        <SummaryCard label="진행중" value={summary.inProgressCount} />
        <SummaryCard
          label="보류"
          value={summary.onHoldCount}
          note="달성률 제외"
        />
        <SummaryCard label="완료" value={summary.completedCount} />
      </div>

      <div className="kanban-grid" aria-label="오늘 상태 칸반">
        {lanes.map((lane) => {
          const tasks = mockTasks.filter((task) => task.status === lane.status);

          return (
            <section className="kanban-lane" key={lane.status}>
              <header>
                <h2>{lane.label}</h2>
                <span>{tasks.length}</span>
              </header>
              <div className="task-list">
                {tasks.map((task) => (
                  <article className="task-card" key={task.id}>
                    <div className="task-card-header">
                      <span className={`priority priority-${task.priority}`}>
                        {priorityLabel(task.priority)}
                      </span>
                      <span className="category-chip">{task.category}</span>
                    </div>
                    <h3>{task.title}</h3>
                  </article>
                ))}
              </div>
            </section>
          );
        })}
      </div>
    </section>
  );
}

function SummaryCard({
  label,
  value,
  note,
}: {
  label: string;
  value: number;
  note?: string;
}) {
  return (
    <article className="summary-card">
      <span>{label}</span>
      <strong>{value}</strong>
      {note ? <small>{note}</small> : null}
    </article>
  );
}

function priorityLabel(priority: MockTask['priority']) {
  switch (priority) {
    case 'high':
      return '높음';
    case 'normal':
      return '보통';
    case 'low':
      return '낮음';
  }
}
