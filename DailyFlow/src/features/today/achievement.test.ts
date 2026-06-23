import { describe, expect, it } from 'vitest';

import { calculateAchievementSummary } from './achievement';

describe('calculateAchievementSummary', () => {
  it('calculates completed over planned plus in-progress plus completed', () => {
    const summary = calculateAchievementSummary([
      { status: 'planned' },
      { status: 'planned' },
      { status: 'in_progress' },
      { status: 'completed' },
      { status: 'completed' },
    ]);

    expect(summary.denominatorCount).toBe(5);
    expect(summary.completedCount).toBe(2);
    expect(summary.achievementRate).toBe(0.4);
  });

  it('excludes on-hold tasks from the denominator', () => {
    const summary = calculateAchievementSummary([
      { status: 'planned' },
      { status: 'completed' },
      { status: 'on_hold' },
      { status: 'on_hold' },
    ]);

    expect(summary.onHoldCount).toBe(2);
    expect(summary.denominatorCount).toBe(2);
    expect(summary.achievementRate).toBe(0.5);
  });

  it('returns zero achievement when there are no countable tasks', () => {
    const summary = calculateAchievementSummary([{ status: 'on_hold' }]);

    expect(summary.denominatorCount).toBe(0);
    expect(summary.achievementRate).toBe(0);
  });
});
