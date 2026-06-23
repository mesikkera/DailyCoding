import { describe, expect, it } from 'vitest';

import {
  carryOverTask,
  countPendingTasks,
  createLocalTask,
  createRecurrenceRule,
  generateTasksForDateFromRules,
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

  it('carries an unfinished task to a destination date', () => {
    const task = transitionTaskStatus(
      createLocalTask({
        title: '이월할 작업',
        scheduledDate: '2026-06-23',
      }),
      'in_progress',
    );
    const carriedOver = carryOverTask(task, '2026-06-24');

    expect(carriedOver.scheduledDate).toBe('2026-06-24');
    expect(carriedOver.originalScheduledDate).toBe('2026-06-23');
    expect(carriedOver.carryOverCount).toBe(1);
    expect(carriedOver.status).toBe('planned');
    expect(carriedOver.completedAt).toBeNull();
    expect(carriedOver.syncState).toBe('pending');
  });

  it('generates one daily recurring task per date without duplicates', () => {
    const rule = createRecurrenceRule({
      title: '매일 회고',
      categoryName: '오늘의 자기 계발',
      startDate: '2026-06-20',
    });
    const firstGeneration = generateTasksForDateFromRules(
      [rule],
      [],
      '2026-06-23',
    );
    const duplicateGeneration = generateTasksForDateFromRules(
      [rule],
      firstGeneration,
      '2026-06-23',
    );

    expect(firstGeneration).toHaveLength(1);
    expect(firstGeneration[0]).toMatchObject({
      title: '매일 회고',
      categoryName: '오늘의 자기 계발',
      recurrenceRuleId: rule.id,
      generatedForDate: '2026-06-23',
    });
    expect(duplicateGeneration).toHaveLength(0);
  });

  it('does not generate inactive or out-of-range recurring tasks', () => {
    const inactiveRule = {
      ...createRecurrenceRule({
        title: '중지된 루틴',
        startDate: '2026-06-20',
      }),
      isActive: false,
    };
    const endedRule = createRecurrenceRule({
      title: '종료된 루틴',
      startDate: '2026-06-20',
      endDate: '2026-06-22',
    });

    expect(
      generateTasksForDateFromRules(
        [inactiveRule, endedRule],
        [],
        '2026-06-23',
      ),
    ).toHaveLength(0);
  });
});
