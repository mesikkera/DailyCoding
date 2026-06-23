import type { ReactNode } from 'react';
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

const lanes: Array<{ label: string; status: TaskStatus; tone: BadgeTone }> = [
  { label: '예정', status: 'planned', tone: 'primary' },
  { label: '진행중', status: 'in_progress', tone: 'warning' },
  { label: '보류', status: 'on_hold', tone: 'muted' },
  { label: '완료', status: 'completed', tone: 'success' },
];

type BadgeTone = 'primary' | 'warning' | 'muted' | 'success';

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
        action={<Button onClick={addTask}>+ 할 일 추가</Button>}
        description="상태 중심 칸반으로 오늘의 계획과 달성률을 봅니다."
        eyebrow="Today Board"
        title="오늘의 흐름"
      />

      <SyncStatusBanner
        isOnline={isOnline}
        onMarkSynced={markPendingTasksSynced}
        pendingCount={pendingCount}
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
          const laneTasks = activeTasks
            .filter((task) => task.status === lane.status)
            .sort((a, b) => a.sortOrder - b.sortOrder);

          return (
            <Card as="section" className="kanban-lane" key={lane.status}>
              <header>
                <h2>{lane.label}</h2>
                <Badge tone={lane.tone}>{laneTasks.length}</Badge>
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
                  <p className="empty-lane">아직 항목이 없습니다.</p>
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
  return (
    <Card as="article" className="task-card">
      <div className="task-card-header">
        <Badge tone={`priority-${task.priority}`}>
          {priorityLabel(task.priority)}
        </Badge>
        <Badge>{task.categoryName}</Badge>
      </div>
      <h3>{task.title}</h3>
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
        {lanes.map((lane) => (
          <button
            aria-pressed={task.status === lane.status}
            className="task-action"
            key={lane.status}
            onClick={() => onStatusChange(task.id, lane.status)}
            type="button"
          >
            {lane.label}
          </button>
        ))}
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
