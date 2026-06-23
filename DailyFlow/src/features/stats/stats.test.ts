import { describe, expect, it } from 'vitest';

import {
  buildStatsDocumentPayload,
  calculateAverageAchievement,
  calculateDailyAchievementRate,
  formatRate,
} from './stats';

describe('stats domain', () => {
  it('calculates daily achievement while excluding on-hold items', () => {
    const rate = calculateDailyAchievementRate({
      date: '2026-06-23',
      plannedCount: 1,
      inProgressCount: 1,
      completedCount: 2,
      onHoldCount: 10,
    });

    expect(formatRate(rate)).toBe('50%');
  });

  it('calculates weekly or monthly averages from task-only denominators', () => {
    const average = calculateAverageAchievement('주간 평균', [
      {
        date: '2026-06-22',
        plannedCount: 1,
        inProgressCount: 0,
        completedCount: 1,
        onHoldCount: 2,
      },
      {
        date: '2026-06-23',
        plannedCount: 0,
        inProgressCount: 1,
        completedCount: 2,
        onHoldCount: 1,
      },
    ]);

    expect(average.completedCount).toBe(3);
    expect(average.denominatorCount).toBe(5);
    expect(formatRate(average.rate)).toBe('60%');
  });

  it('builds canonical daily stat payload metadata', () => {
    expect(
      buildStatsDocumentPayload({
        date: '2026-06-23',
        plannedCount: 1,
        inProgressCount: 1,
        completedCount: 1,
        onHoldCount: 1,
      }),
    ).toMatchObject({
      achievementRate: 1 / 3,
      denominatorCount: 3,
      excludedCount: 1,
      includeEvents: false,
    });
  });
});
