import type { CreateTaskInput, DailyFlowTask, TaskStatus } from './task';

export interface TaskRepository {
  listTasksForDate(
    userId: string,
    scheduledDate: string,
  ): Promise<DailyFlowTask[]>;
  createTask(userId: string, input: CreateTaskInput): Promise<DailyFlowTask>;
  updateTaskStatus(
    userId: string,
    taskId: string,
    status: TaskStatus,
  ): Promise<void>;
  softDeleteTask(userId: string, taskId: string): Promise<void>;
}
