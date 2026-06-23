export type TaskStatus = 'planned' | 'in_progress' | 'on_hold' | 'completed';

export interface AchievementInput {
  status: TaskStatus;
}

export interface AchievementSummary {
  plannedCount: number;
  inProgressCount: number;
  onHoldCount: number;
  completedCount: number;
  denominatorCount: number;
  achievementRate: number;
}

export function calculateAchievementSummary(
  tasks: AchievementInput[],
): AchievementSummary {
  const summary = tasks.reduce(
    (acc, task) => {
      switch (task.status) {
        case 'planned':
          acc.plannedCount += 1;
          break;
        case 'in_progress':
          acc.inProgressCount += 1;
          break;
        case 'on_hold':
          acc.onHoldCount += 1;
          break;
        case 'completed':
          acc.completedCount += 1;
          break;
      }

      return acc;
    },
    {
      plannedCount: 0,
      inProgressCount: 0,
      onHoldCount: 0,
      completedCount: 0,
    },
  );

  const denominatorCount =
    summary.plannedCount + summary.inProgressCount + summary.completedCount;

  return {
    ...summary,
    denominatorCount,
    achievementRate:
      denominatorCount === 0 ? 0 : summary.completedCount / denominatorCount,
  };
}
