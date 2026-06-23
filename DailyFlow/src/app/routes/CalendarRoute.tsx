import { PageHeader } from '../../components/ui/PageHeader';
import { PlaceholderPanel } from '../../components/ui/PlaceholderPanel';

export function CalendarRoute() {
  return (
    <section className="page-surface" aria-labelledby="calendar-heading">
      <PageHeader
        description="주간 보기를 기본으로 일정과 날짜별 달성률을 함께 보여줄 예정입니다."
        eyebrow="Calendar"
        title="캘린더"
      />
      <PlaceholderPanel
        title="주간 캘린더 MVP"
        description="일정 이벤트는 할 일과 분리되고 달성률에는 포함되지 않습니다."
        bullets={[
          '주간 보기 기본, 일/월 보기 전환',
          '대한민국 공휴일 표시',
          '날짜별 할 일 배치와 달성률 표시',
        ]}
      />
    </section>
  );
}
