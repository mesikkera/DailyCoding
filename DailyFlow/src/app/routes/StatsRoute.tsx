import { PageHeader } from '../../components/ui/PageHeader';
import { PlaceholderPanel } from '../../components/ui/PlaceholderPanel';

export function StatsRoute() {
  return (
    <section className="page-surface" aria-labelledby="stats-heading">
      <PageHeader
        description="일별 달성률을 중심으로 주간·월간 평균을 확인합니다."
        eyebrow="Stats"
        title="통계"
      />
      <PlaceholderPanel
        title="달성률 통계 MVP"
        description="통계는 할 일만 기준으로 계산하며 보류와 일정은 제외합니다."
        bullets={['일별 달성률', '주간 평균 달성률', '월간 평균 달성률']}
      />
    </section>
  );
}
