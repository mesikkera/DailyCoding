import type { CSSProperties } from 'react';
import { useMemo, useState } from 'react';

import { Badge } from '../../components/ui/Badge';
import { Button } from '../../components/ui/Button';
import { Card } from '../../components/ui/Card';
import { PageHeader } from '../../components/ui/PageHeader';
import { SyncStatusBanner } from '../sync/SyncStatusBanner';
import { useOnlineStatus } from '../sync/useOnlineStatus';
import {
  carryOverTask,
  countPendingTasks,
  createLocalTask,
  markTaskSynced,
  softDeleteTask,
  transitionTaskStatus,
  visibleTasks,
  type DailyFlowTask,
  type TaskPriority,
  type TaskStatus,
} from '../tasks/task';
import { calculateAchievementSummary } from './achievement';

const today = new Date().toISOString().slice(0, 10);

const initialTasks: DailyFlowTask[] = [
  createSeedTask({
    id: 'task-1',
    title: '아침 루틴 정리',
    categoryName: '오늘의 생활',
    priority: 'normal',
    status: 'planned',
    sortOrder: 10,
  }),
  createSeedTask({
    id: 'task-2',
    title: 'DailyFlow 설계 문서 검토',
    categoryName: '오늘의 업무',
    priority: 'high',
    status: 'in_progress',
    sortOrder: 20,
  }),
  createSeedTask({
    id: 'task-3',
    title: '운동 30분',
    categoryName: '오늘의 자기 계발',
    priority: 'normal',
    status: 'completed',
    sortOrder: 30,
  }),
  createSeedTask({
    id: 'task-4',
    title: '장기 보류 아이디어 정리',
    categoryName: '오늘의 할 일',
    priority: 'low',
    status: 'on_hold',
    sortOrder: 40,
  }),
];

const categories: Array<{ name: string; accent: string }> = [
  { name: '오늘의 생활', accent: 'blue' },
  { name: '오늘의 할 일', accent: 'purple' },
  { name: '오늘의 자기 계발', accent: 'green' },
  { name: '오늘의 업무', accent: 'orange' },
];

export function TodayBoardPlaceholder() {
  const isOnline = useOnlineStatus();
  const [tasks, setTasks] = useState<DailyFlowTask[]>(initialTasks);
  const visibleTaskList = useMemo(() => visibleTasks(tasks), [tasks]);
  const activeTasks = useMemo(
    () => visibleTaskList.filter((task) => task.scheduledDate === today),
    [visibleTaskList],
  );
  const summary = calculateAchievementSummary(activeTasks);
  const percentage = Math.round(summary.achievementRate * 100);
  const pendingCount = countPendingTasks(visibleTaskList);

  const addTask = () => {
    setTasks((currentTasks) => [
      ...currentTasks,
      createLocalTask({
        title: `새 할 일 ${currentTasks.length + 1}`,
        categoryName: '오늘의 할 일',
        priority: 'normal',
        scheduledDate: today,
      }),
    ]);
  };

  const updateStatus = (taskId: string, status: TaskStatus) => {
    setTasks((currentTasks) =>
      currentTasks.map((task) => {
        return task.id === taskId ? transitionTaskStatus(task, status) : task;
      }),
    );
  };

  const deleteTask = (taskId: string) => {
    setTasks((currentTasks) =>
      currentTasks.map((task) => {
        return task.id === taskId ? softDeleteTask(task) : task;
      }),
    );
  };

  const carryOverToTomorrow = (taskId: string) => {
    setTasks((currentTasks) =>
      currentTasks.map((task) => {
        return task.id === taskId ? carryOverTask(task, nextDate(today)) : task;
      }),
    );
  };

  const markPendingTasksSynced = () => {
    if (!isOnline) {
      return;
    }

    setTasks((currentTasks) =>
      currentTasks.map((task) => {
        return task.syncState === 'pending' ? markTaskSynced(task) : task;
      }),
    );
  };

  return (
    <section className="today-board" aria-labelledby="today-heading">
      <PageHeader
        action={<Button onClick={addTask}>새 할 일</Button>}
        description="오늘 처리할 일만 차분하게 정리하고, 완료율은 자동으로 계산합니다."
        eyebrow={formatFullDate(today)}
        title="오늘"
      />

      <div className="today-dashboard">
        <Card className="today-hero-card">
          <div
            aria-label={`오늘 달성률 ${percentage}%`}
            className="achievement-ring"
            style={{ '--achievement': `${percentage}%` } as CSSProperties}
          >
            <span>{percentage}%</span>
          </div>
          <div className="today-hero-copy">
            <p>오늘의 달성률</p>
            <strong>
              완료 {summary.completedCount} / 대상 {summary.denominatorCount}
            </strong>
            <span>보류 {summary.onHoldCount}개는 달성률에서 제외됩니다.</span>
          </div>
        </Card>

        <div className="today-metric-strip" aria-label="오늘 카테고리 요약">
          <MetricPill label="전체 계획" value={summary.denominatorCount} />
          <MetricPill label="완료" value={summary.completedCount} />
          <MetricPill label="보류" value={summary.onHoldCount} />
        </div>
      </div>

      <SyncStatusBanner
        isOnline={isOnline}
        onMarkSynced={markPendingTasksSynced}
        pendingCount={pendingCount}
      />

      <div className="board-section-header">
        <div>
          <h2>카테고리별 오늘 보드</h2>
          <p>
            날짜별 하루 안에서 생활, 할 일, 자기 계발, 업무를 나누어 관리합니다.
          </p>
        </div>
        <div className="category-preview" aria-label="오늘 카테고리">
          <span>생활</span>
          <span>할 일</span>
          <span>자기 계발</span>
          <span>업무</span>
        </div>
      </div>

      <div
        className="kanban-grid category-kanban-grid"
        aria-label="오늘 카테고리 칸반"
      >
        {categories.map((category) => {
          const laneTasks = activeTasks
            .filter((task) => task.categoryName === category.name)
            .sort((a, b) => a.sortOrder - b.sortOrder);
          const laneSummary = calculateAchievementSummary(laneTasks);
          const lanePercentage = Math.round(laneSummary.achievementRate * 100);

          return (
            <Card
              as="section"
              className={`kanban-lane category-lane category-lane-${category.accent}`}
              key={category.name}
            >
              <header>
                <div>
                  <h2>{category.name}</h2>
                  <small>달성률 {lanePercentage}%</small>
                </div>
                <Badge tone="primary">
                  {laneSummary.completedCount}/{laneSummary.denominatorCount}
                </Badge>
              </header>
              <div className="task-list">
                {laneTasks.length > 0 ? (
                  laneTasks.map((task) => (
                    <TaskCard
                      key={task.id}
                      onCarryOver={carryOverToTomorrow}
                      onDelete={deleteTask}
                      onStatusChange={updateStatus}
                      task={task}
                    />
                  ))
                ) : (
                  <p className="empty-lane">이 카테고리에 할 일이 없습니다.</p>
                )}
              </div>
            </Card>
          );
        })}
      </div>
    </section>
  );
}

function TaskCard({
  onCarryOver,
  onDelete,
  onStatusChange,
  task,
}: {
  onCarryOver: (taskId: string) => void;
  onDelete: (taskId: string) => void;
  onStatusChange: (taskId: string, status: TaskStatus) => void;
  task: DailyFlowTask;
}) {
  const isCompleted = task.status === 'completed';

  return (
    <Card
      as="article"
      className={`task-card ${isCompleted ? 'task-card-completed' : ''}`}
    >
      <div className="task-card-main">
        <button
          aria-label={`${task.title} 완료`}
          className="completion-control"
          onClick={() => onStatusChange(task.id, 'completed')}
          type="button"
        >
          {isCompleted ? '✓' : ''}
        </button>
        <div>
          <h3>{task.title}</h3>
          <div className="task-card-header">
            <Badge tone={`priority-${task.priority}`}>
              {priorityLabel(task.priority)}
            </Badge>
            <Badge>{task.categoryName}</Badge>
          </div>
        </div>
      </div>
      <div className="task-card-meta">
        <Badge tone={syncBadgeTone(task.syncState)}>
          {syncLabel(task.syncState)}
        </Badge>
        {task.lastSyncedAt ? (
          <small>마지막 동기화 {formatTime(task.lastSyncedAt)}</small>
        ) : (
          <small>로컬 변경 저장됨</small>
        )}
      </div>
      <div className="task-actions" aria-label={`${task.title} 상태 변경`}>
        <button
          aria-pressed={task.status === 'in_progress'}
          className="task-action"
          onClick={() => onStatusChange(task.id, 'in_progress')}
          type="button"
        >
          진행중
        </button>
        <button
          aria-pressed={task.status === 'on_hold'}
          className="task-action"
          onClick={() => onStatusChange(task.id, 'on_hold')}
          type="button"
        >
          보류
        </button>
        <button
          aria-pressed={task.status === 'completed'}
          className="task-action"
          onClick={() => onStatusChange(task.id, 'completed')}
          type="button"
        >
          완료
        </button>
        <button
          className="task-action"
          onClick={() => onCarryOver(task.id)}
          type="button"
        >
          내일로 이월
        </button>
        <button
          className="task-action task-action-danger"
          onClick={() => onDelete(task.id)}
          type="button"
        >
          삭제
        </button>
      </div>
    </Card>
  );
}

function MetricPill({ label, value }: { label: string; value: number }) {
  return (
    <div className="metric-pill">
      <span>{label}</span>
      <strong>{value}</strong>
    </div>
  );
}

function priorityLabel(priority: TaskPriority) {
  switch (priority) {
    case 'high':
      return '높음';
    case 'normal':
      return '보통';
    case 'low':
      return '낮음';
  }
}

function createSeedTask({
  categoryName,
  id,
  priority,
  sortOrder,
  status,
  title,
}: {
  categoryName: string;
  id: string;
  priority: TaskPriority;
  sortOrder: number;
  status: TaskStatus;
  title: string;
}): DailyFlowTask {
  const task = createLocalTask({
    title,
    categoryName,
    priority,
    scheduledDate: today,
  });

  return markTaskSynced(
    transitionTaskStatus(
      {
        ...task,
        id,
        sortOrder,
      },
      status,
    ),
  );
}

function syncLabel(syncState: DailyFlowTask['syncState']) {
  switch (syncState) {
    case 'synced':
      return '동기화됨';
    case 'pending':
      return '동기화 대기';
    case 'error':
      return '동기화 오류';
  }
}

function syncBadgeTone(syncState: DailyFlowTask['syncState']) {
  switch (syncState) {
    case 'synced':
      return 'success';
    case 'pending':
      return 'warning';
    case 'error':
      return 'muted';
  }
}

function formatTime(isoDate: string) {
  return new Intl.DateTimeFormat('ko-KR', {
    hour: '2-digit',
    minute: '2-digit',
  }).format(new Date(isoDate));
}

function nextDate(date: string) {
  const nextDay = new Date(`${date}T00:00:00.000Z`);
  nextDay.setUTCDate(nextDay.getUTCDate() + 1);

  return nextDay.toISOString().slice(0, 10);
}

function formatFullDate(date: string) {
  return new Intl.DateTimeFormat('ko-KR', {
    month: 'long',
    day: 'numeric',
    weekday: 'long',
  }).format(new Date(`${date}T00:00:00.000Z`));
}
