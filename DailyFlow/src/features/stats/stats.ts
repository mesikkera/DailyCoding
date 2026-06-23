export interface DailyAchievementStat {
  date: string;
  plannedCount: number;
  inProgressCount: number;
  completedCount: number;
  onHoldCount: number;
}

export interface AchievementAverage {
  label: string;
  rate: number;
  completedCount: number;
  denominatorCount: number;
}

export function calculateDailyAchievementRate(stat: DailyAchievementStat) {
  const denominatorCount =
    stat.plannedCount + stat.inProgressCount + stat.completedCount;

  return denominatorCount === 0 ? 0 : stat.completedCount / denominatorCount;
}

export function calculateAverageAchievement(
  label: string,
  stats: DailyAchievementStat[],
): AchievementAverage {
  const completedCount = stats.reduce(
    (total, stat) => total + stat.completedCount,
    0,
  );
  const denominatorCount = stats.reduce((total, stat) => {
    return (
      total + stat.plannedCount + stat.inProgressCount + stat.completedCount
    );
  }, 0);

  return {
    label,
    completedCount,
    denominatorCount,
    rate: denominatorCount === 0 ? 0 : completedCount / denominatorCount,
  };
}

export function formatRate(rate: number) {
  return `${Math.round(rate * 100)}%`;
}

export function buildStatsDocumentPayload(stat: DailyAchievementStat) {
  return {
    ...stat,
    achievementRate: calculateDailyAchievementRate(stat),
    denominatorCount:
      stat.plannedCount + stat.inProgressCount + stat.completedCount,
    excludedCount: stat.onHoldCount,
    includeEvents: false,
  };
}
