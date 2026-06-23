import { describe, expect, it } from 'vitest';

import {
  countPendingTasks,
  createLocalTask,
  markTaskSynced,
  softDeleteTask,
  transitionTaskStatus,
} from './task';

describe('task domain', () => {
  it('creates a planned local task with defaults', () => {
    const task = createLocalTask({
      title: '  새 작업  ',
      scheduledDate: '2026-06-23',
    });

    expect(task.title).toBe('새 작업');
    expect(task.status).toBe('planned');
    expect(task.priority).toBe('normal');
    expect(task.categoryName).toBe('오늘의 할 일');
    expect(task.syncState).toBe('pending');
    expect(task.lastSyncedAt).toBeNull();
  });

  it('sets completedAt only while task is completed', () => {
    const task = createLocalTask({
      title: '운동',
      scheduledDate: '2026-06-23',
    });
    const completed = transitionTaskStatus(task, 'completed');
    const reopened = transitionTaskStatus(completed, 'in_progress');

    expect(completed.completedAt).toEqual(expect.any(String));
    expect(completed.syncState).toBe('pending');
    expect(reopened.completedAt).toBeNull();
  });

  it('soft deletes without losing the task payload', () => {
    const task = createLocalTask({
      title: '삭제할 작업',
      scheduledDate: '2026-06-23',
    });
    const deleted = softDeleteTask(task);

    expect(deleted.title).toBe(task.title);
    expect(deleted.deletedAt).toEqual(expect.any(String));
    expect(deleted.syncState).toBe('pending');
  });

  it('marks pending tasks as synced after remote persistence', () => {
    const task = createLocalTask({
      title: '동기화할 작업',
      scheduledDate: '2026-06-23',
    });
    const synced = markTaskSynced(task);

    expect(synced.syncState).toBe('synced');
    expect(synced.lastSyncedAt).toEqual(expect.any(String));
    expect(countPendingTasks([task, synced])).toBe(1);
  });
});
