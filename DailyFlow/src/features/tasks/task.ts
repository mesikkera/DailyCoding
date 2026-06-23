export type TaskStatus = 'planned' | 'in_progress' | 'on_hold' | 'completed';
export type TaskPriority = 'high' | 'normal' | 'low';
export type TaskSyncState = 'synced' | 'pending' | 'error';

export interface DailyFlowTask {
  id: string;
  title: string;
  description: string | null;
  categoryId: string | null;
  categoryName: string;
  scheduledDate: string;
  originalScheduledDate: string | null;
  carriedOverFromTaskId: string | null;
  carryOverCount: number;
  status: TaskStatus;
  priority: TaskPriority;
  completedAt: string | null;
  sortOrder: number;
  createdAt: string;
  updatedAt: string;
  clientUpdatedAt: string;
  deletedAt: string | null;
  syncState: TaskSyncState;
  lastSyncedAt: string | null;
  syncError: string | null;
  schemaVersion: 1;
}

export interface CreateTaskInput {
  title: string;
  categoryId?: string | null;
  categoryName?: string;
  priority?: TaskPriority;
  scheduledDate: string;
}

export function createLocalTask(input: CreateTaskInput): DailyFlowTask {
  const now = new Date().toISOString();
  const id = `local-${crypto.randomUUID()}`;

  return {
    id,
    title: input.title.trim(),
    description: null,
    categoryId: input.categoryId ?? null,
    categoryName: input.categoryName ?? '오늘의 할 일',
    scheduledDate: input.scheduledDate,
    originalScheduledDate: null,
    carriedOverFromTaskId: null,
    carryOverCount: 0,
    status: 'planned',
    priority: input.priority ?? 'normal',
    completedAt: null,
    sortOrder: Date.now(),
    createdAt: now,
    updatedAt: now,
    clientUpdatedAt: now,
    deletedAt: null,
    syncState: 'pending',
    lastSyncedAt: null,
    syncError: null,
    schemaVersion: 1,
  };
}

export function transitionTaskStatus(
  task: DailyFlowTask,
  status: TaskStatus,
): DailyFlowTask {
  const now = new Date().toISOString();

  return {
    ...task,
    status,
    completedAt: status === 'completed' ? (task.completedAt ?? now) : null,
    updatedAt: now,
    clientUpdatedAt: now,
    syncState: 'pending',
    syncError: null,
  };
}

export function softDeleteTask(task: DailyFlowTask): DailyFlowTask {
  const now = new Date().toISOString();

  return {
    ...task,
    deletedAt: now,
    updatedAt: now,
    clientUpdatedAt: now,
    syncState: 'pending',
    syncError: null,
  };
}

export function visibleTasks(tasks: DailyFlowTask[]) {
  return tasks.filter((task) => task.deletedAt === null);
}

export function markTaskSynced(task: DailyFlowTask): DailyFlowTask {
  const now = new Date().toISOString();

  return {
    ...task,
    syncState: 'synced',
    lastSyncedAt: now,
    syncError: null,
  };
}

export function markTaskSyncError(
  task: DailyFlowTask,
  syncError: string,
): DailyFlowTask {
  return {
    ...task,
    syncState: 'error',
    syncError,
  };
}

export function countPendingTasks(tasks: DailyFlowTask[]) {
  return tasks.filter((task) => task.syncState === 'pending').length;
}
