export type TaskStatus = 'planned' | 'in_progress' | 'on_hold' | 'completed';
export type TaskPriority = 'high' | 'normal' | 'low';
export type TaskSyncState = 'synced' | 'pending' | 'error';
export type RecurrenceFrequency = 'daily';

export interface DailyFlowRecurrenceRule {
  id: string;
  title: string;
  categoryId: string | null;
  categoryName: string;
  priority: TaskPriority;
  frequency: RecurrenceFrequency;
  startDate: string;
  endDate: string | null;
  isActive: boolean;
  createdAt: string;
  updatedAt: string;
  schemaVersion: 1;
}

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
  recurrenceRuleId: string | null;
  generatedForDate: string | null;
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
  recurrenceRuleId?: string | null;
  generatedForDate?: string | null;
}

export interface CreateRecurrenceRuleInput {
  title: string;
  categoryId?: string | null;
  categoryName?: string;
  priority?: TaskPriority;
  startDate: string;
  endDate?: string | null;
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
    recurrenceRuleId: input.recurrenceRuleId ?? null,
    generatedForDate: input.generatedForDate ?? null,
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

export function carryOverTask(
  task: DailyFlowTask,
  destinationDate: string,
): DailyFlowTask {
  const now = new Date().toISOString();

  return {
    ...task,
    scheduledDate: destinationDate,
    originalScheduledDate: task.originalScheduledDate ?? task.scheduledDate,
    carryOverCount: task.carryOverCount + 1,
    status: 'planned',
    completedAt: null,
    updatedAt: now,
    clientUpdatedAt: now,
    syncState: 'pending',
    syncError: null,
  };
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

export function createRecurrenceRule(
  input: CreateRecurrenceRuleInput,
): DailyFlowRecurrenceRule {
  const now = new Date().toISOString();

  return {
    id: `rule-${crypto.randomUUID()}`,
    title: input.title.trim(),
    categoryId: input.categoryId ?? null,
    categoryName: input.categoryName ?? '오늘의 할 일',
    priority: input.priority ?? 'normal',
    frequency: 'daily',
    startDate: input.startDate,
    endDate: input.endDate ?? null,
    isActive: true,
    createdAt: now,
    updatedAt: now,
    schemaVersion: 1,
  };
}

export function generateTasksForDateFromRules(
  rules: DailyFlowRecurrenceRule[],
  existingTasks: DailyFlowTask[],
  scheduledDate: string,
) {
  const generatedTasks: DailyFlowTask[] = [];

  for (const rule of rules) {
    if (!shouldGenerateRuleForDate(rule, scheduledDate)) {
      continue;
    }

    const alreadyGenerated = existingTasks.some((task) => {
      return (
        task.deletedAt === null &&
        task.recurrenceRuleId === rule.id &&
        task.generatedForDate === scheduledDate
      );
    });

    if (alreadyGenerated) {
      continue;
    }

    generatedTasks.push(
      createLocalTask({
        title: rule.title,
        categoryId: rule.categoryId,
        categoryName: rule.categoryName,
        priority: rule.priority,
        scheduledDate,
        recurrenceRuleId: rule.id,
        generatedForDate: scheduledDate,
      }),
    );
  }

  return generatedTasks;
}

function shouldGenerateRuleForDate(
  rule: DailyFlowRecurrenceRule,
  scheduledDate: string,
) {
  return (
    rule.isActive &&
    rule.frequency === 'daily' &&
    scheduledDate >= rule.startDate &&
    (rule.endDate === null || scheduledDate <= rule.endDate)
  );
}
