import { useMemo, useState } from 'react';

import { Badge } from '../../components/ui/Badge';
import { Button } from '../../components/ui/Button';
import { Card } from '../../components/ui/Card';
import { PageHeader } from '../../components/ui/PageHeader';
import {
  createCalendarEvent,
  eventFallsOnDate,
  formatAchievement,
  getKoreanHolidayName,
  getMonthGridDates,
  getWeekDates,
  type CalendarDaySummary,
  type CalendarView,
  type DailyFlowCalendarEvent,
} from '../../features/calendar/calendar';

const today = new Date().toISOString().slice(0, 10);

const viewOptions: Array<{ label: string; value: CalendarView }> = [
  { label: '일', value: 'day' },
  { label: '주', value: 'week' },
  { label: '월', value: 'month' },
];

const sampleSummaries: CalendarDaySummary[] = [
  {
    date: today,
    plannedTaskCount: 4,
    completedTaskCount: 1,
    achievementRate: 0.25,
  },
  {
    date: getWeekDates(today)[2],
    plannedTaskCount: 3,
    completedTaskCount: 2,
    achievementRate: 0.67,
  },
];

export function CalendarRoute() {
  const [activeView, setActiveView] = useState<CalendarView>('week');
  const [events, setEvents] = useState<DailyFlowCalendarEvent[]>([
    createCalendarEvent({ date: today, title: '주간 계획 정리' }),
  ]);
  const visibleDates = useMemo(() => {
    if (activeView === 'day') {
      return [today];
    }

    return activeView === 'week'
      ? getWeekDates(today)
      : getMonthGridDates(today);
  }, [activeView]);

  const addEvent = () => {
    setEvents((currentEvents) => [
      ...currentEvents,
      createCalendarEvent({
        date: today,
        title: `새 일정 ${currentEvents.length + 1}`,
      }),
    ]);
  };

  return (
    <section className="page-surface" aria-labelledby="calendar-heading">
      <PageHeader
        action={<Button onClick={addEvent}>+ 일정 추가</Button>}
        description="주간 보기를 기본으로 일정과 날짜별 달성률을 함께 보여줍니다. 일정은 할 일 달성률에 포함되지 않습니다."
        eyebrow="Calendar"
        title="캘린더"
      />

      <div className="segmented-control" aria-label="캘린더 보기 선택">
        {viewOptions.map((option) => (
          <button
            aria-pressed={activeView === option.value}
            key={option.value}
            onClick={() => setActiveView(option.value)}
            type="button"
          >
            {option.label}
          </button>
        ))}
      </div>

      <div className={`calendar-grid calendar-grid-${activeView}`}>
        {visibleDates.map((date) => (
          <CalendarDayCell
            date={date}
            events={events.filter((event) => eventFallsOnDate(event, date))}
            key={date}
            summary={sampleSummaries.find((summary) => summary.date === date)}
          />
        ))}
      </div>
    </section>
  );
}

function CalendarDayCell({
  date,
  events,
  summary,
}: {
  date: string;
  events: DailyFlowCalendarEvent[];
  summary?: CalendarDaySummary;
}) {
  const holidayName = getKoreanHolidayName(date);

  return (
    <Card as="article" className="calendar-day-card">
      <header>
        <div>
          <strong>{formatCalendarDate(date)}</strong>
          <span>{weekdayLabel(date)}</span>
        </div>
        {holidayName ? <Badge tone="warning">{holidayName}</Badge> : null}
      </header>
      <div className="calendar-day-metrics">
        <Badge tone="primary">달성률 {formatAchievement(summary)}</Badge>
        <small>
          할 일 {summary?.completedTaskCount ?? 0} /{' '}
          {summary?.plannedTaskCount ?? 0}
        </small>
      </div>
      <div className="calendar-events">
        {events.length > 0 ? (
          events.map((event) => (
            <div className="calendar-event" key={event.id}>
              <strong>{event.title}</strong>
              <span>
                {formatEventTime(event.startsAt)}–
                {formatEventTime(event.endsAt)} · 알림{' '}
                {event.reminder.minutesBefore}분 전
              </span>
            </div>
          ))
        ) : (
          <p>등록된 일정이 없습니다.</p>
        )}
      </div>
    </Card>
  );
}

function formatCalendarDate(date: string) {
  return new Intl.DateTimeFormat('ko-KR', {
    month: 'short',
    day: 'numeric',
  }).format(new Date(`${date}T00:00:00.000Z`));
}

function weekdayLabel(date: string) {
  return new Intl.DateTimeFormat('ko-KR', { weekday: 'short' }).format(
    new Date(`${date}T00:00:00.000Z`),
  );
}

function formatEventTime(isoDate: string) {
  return new Intl.DateTimeFormat('ko-KR', {
    hour: '2-digit',
    minute: '2-digit',
  }).format(new Date(isoDate));
}
