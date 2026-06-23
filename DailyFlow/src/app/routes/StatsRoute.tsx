import { Badge } from '../../components/ui/Badge';
import { Card } from '../../components/ui/Card';
import { PageHeader } from '../../components/ui/PageHeader';
import {
  buildStatsDocumentPayload,
  calculateAverageAchievement,
  calculateDailyAchievementRate,
  formatRate,
  type DailyAchievementStat,
} from '../../features/stats/stats';

const sampleStats: DailyAchievementStat[] = [
  {
    date: '2026-06-22',
    plannedCount: 1,
    inProgressCount: 1,
    completedCount: 2,
    onHoldCount: 1,
  },
  {
    date: '2026-06-23',
    plannedCount: 2,
    inProgressCount: 1,
    completedCount: 1,
    onHoldCount: 1,
  },
  {
    date: '2026-06-24',
    plannedCount: 1,
    inProgressCount: 0,
    completedCount: 3,
    onHoldCount: 0,
  },
];

export function StatsRoute() {
  const weeklyAverage = calculateAverageAchievement('주간 평균', sampleStats);
  const monthlyAverage = calculateAverageAchievement('월간 평균', [
    ...sampleStats,
    {
      date: '2026-06-25',
      plannedCount: 3,
      inProgressCount: 1,
      completedCount: 4,
      onHoldCount: 2,
    },
  ]);
  const todayPayload = buildStatsDocumentPayload(sampleStats[1]);

  return (
    <section className="page-surface" aria-labelledby="stats-heading">
      <PageHeader
        description="일별 달성률을 중심으로 주간·월간 평균을 확인합니다. 보류와 일정 이벤트는 통계에서 제외됩니다."
        eyebrow="Stats"
        title="통계"
      />

      <div className="stats-summary-grid" aria-label="통계 요약">
        <StatsSummaryCard
          label="오늘 달성률"
          meta={`완료 ${todayPayload.completedCount} / 대상 ${todayPayload.denominatorCount}`}
          value={formatRate(todayPayload.achievementRate)}
        />
        <StatsSummaryCard
          label={weeklyAverage.label}
          meta={`완료 ${weeklyAverage.completedCount} / 대상 ${weeklyAverage.denominatorCount}`}
          value={formatRate(weeklyAverage.rate)}
        />
        <StatsSummaryCard
          label={monthlyAverage.label}
          meta={`완료 ${monthlyAverage.completedCount} / 대상 ${monthlyAverage.denominatorCount}`}
          value={formatRate(monthlyAverage.rate)}
        />
      </div>

      <Card className="stats-table-card">
        <header>
          <div>
            <h2>일별 달성률</h2>
            <p>예정/진행중/완료만 달성률 대상이며 보류와 일정은 제외됩니다.</p>
          </div>
          <Badge tone="primary">Task-only</Badge>
        </header>
        <div className="stats-day-list">
          {sampleStats.map((stat) => (
            <DailyStatRow key={stat.date} stat={stat} />
          ))}
        </div>
      </Card>
    </section>
  );
}

function StatsSummaryCard({
  label,
  meta,
  value,
}: {
  label: string;
  meta: string;
  value: string;
}) {
  return (
    <Card className="summary-card" tone="hero">
      <span>{label}</span>
      <strong>{value}</strong>
      <small>{meta}</small>
    </Card>
  );
}

function DailyStatRow({ stat }: { stat: DailyAchievementStat }) {
  const rate = calculateDailyAchievementRate(stat);

  return (
    <article className="stats-day-row">
      <div>
        <strong>{stat.date}</strong>
        <span>달성률 {formatRate(rate)}</span>
      </div>
      <dl>
        <div>
          <dt>예정</dt>
          <dd>{stat.plannedCount}</dd>
        </div>
        <div>
          <dt>진행중</dt>
          <dd>{stat.inProgressCount}</dd>
        </div>
        <div>
          <dt>완료</dt>
          <dd>{stat.completedCount}</dd>
        </div>
        <div>
          <dt>보류 제외</dt>
          <dd>{stat.onHoldCount}</dd>
        </div>
      </dl>
    </article>
  );
}
