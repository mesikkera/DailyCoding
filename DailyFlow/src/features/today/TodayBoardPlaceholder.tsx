import type { ReactNode } from 'react';

import { Badge } from '../../components/ui/Badge';
import { Button } from '../../components/ui/Button';
import { Card } from '../../components/ui/Card';
import { PageHeader } from '../../components/ui/PageHeader';
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

const lanes: Array<{ label: string; status: TaskStatus; tone: BadgeTone }> = [
  { label: '예정', status: 'planned', tone: 'primary' },
  { label: '진행중', status: 'in_progress', tone: 'warning' },
  { label: '보류', status: 'on_hold', tone: 'muted' },
  { label: '완료', status: 'completed', tone: 'success' },
];

type BadgeTone = 'primary' | 'warning' | 'muted' | 'success';

export function TodayBoardPlaceholder() {
  const summary = calculateAchievementSummary(mockTasks);
  const percentage = Math.round(summary.achievementRate * 100);

  return (
    <section className="today-board" aria-labelledby="today-heading">
      <PageHeader
        action={<Button>+ 할 일 추가</Button>}
        description="상태 중심 칸반으로 오늘의 계획과 달성률을 봅니다."
        eyebrow="Today Board"
        title="오늘의 흐름"
      />

      <div className="summary-grid" aria-label="오늘 요약">
        <SummaryCard hero label="달성률" value={`${percentage}%`}>
          완료 {summary.completedCount} / 대상 {summary.denominatorCount}
        </SummaryCard>
        <SummaryCard label="예정" value={summary.plannedCount} />
        <SummaryCard label="진행중" value={summary.inProgressCount} />
        <SummaryCard label="보류" value={summary.onHoldCount}>
          달성률 제외
        </SummaryCard>
        <SummaryCard label="완료" value={summary.completedCount} />
      </div>

      <div className="kanban-grid" aria-label="오늘 상태 칸반">
        {lanes.map((lane) => {
          const tasks = mockTasks.filter((task) => task.status === lane.status);

          return (
            <Card as="section" className="kanban-lane" key={lane.status}>
              <header>
                <h2>{lane.label}</h2>
                <Badge tone={lane.tone}>{tasks.length}</Badge>
              </header>
              <div className="task-list">
                {tasks.map((task) => (
                  <Card as="article" className="task-card" key={task.id}>
                    <div className="task-card-header">
                      <Badge tone={`priority-${task.priority}`}>
                        {priorityLabel(task.priority)}
                      </Badge>
                      <Badge>{task.category}</Badge>
                    </div>
                    <h3>{task.title}</h3>
                  </Card>
                ))}
              </div>
            </Card>
          );
        })}
      </div>
    </section>
  );
}

function SummaryCard({
  children,
  hero = false,
  label,
  value,
}: {
  children?: ReactNode;
  hero?: boolean;
  label: string;
  value: number | string;
}) {
  return (
    <Card className="summary-card" tone={hero ? 'hero' : 'default'}>
      <span>{label}</span>
      <strong>{value}</strong>
      {children ? <small>{children}</small> : null}
    </Card>
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
