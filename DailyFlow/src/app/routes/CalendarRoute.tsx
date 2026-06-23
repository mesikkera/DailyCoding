import { useMemo, useState } from 'react';

import { Badge } from '../../components/ui/Badge';
import { Button } from '../../components/ui/Button';
import { Card } from '../../components/ui/Card';
import { PageHeader } from '../../components/ui/PageHeader';
import {
  calculateAverageAchievementRate,
  createCalendarEvent,
  eventFallsOnDate,
  eventStartsAtHour,
  formatAchievement,
  getKoreanHolidayName,
  getMonthGridDates,
  getWeekDates,
  type CalendarDaySummary,
  type CalendarView,
  type DailyFlowCalendarEvent,
} from '../../features/calendar/calendar';

const today = new Date().toISOString().slice(0, 10);
const hourSlots = Array.from({ length: 24 }, (_, hour) => hour);

const viewOptions: Array<{ label: string; value: CalendarView }> = [
  { label: '일', value: 'day' },
  { label: '주', value: 'week' },
  { label: '월', value: 'month' },
];

const weekDates = getWeekDates(today);
const sampleSummaries: CalendarDaySummary[] = [
  {
    date: weekDates[0],
    plannedTaskCount: 3,
    completedTaskCount: 2,
    achievementRate: 0.67,
  },
  {
    date: today,
    plannedTaskCount: 4,
    completedTaskCount: 1,
    achievementRate: 0.25,
  },
  {
    date: weekDates[4],
    plannedTaskCount: 5,
    completedTaskCount: 4,
    achievementRate: 0.8,
  },
];

export function CalendarRoute() {
  const [activeView, setActiveView] = useState<CalendarView>('week');
  const [events, setEvents] = useState<DailyFlowCalendarEvent[]>([
    createCalendarEvent({ date: today, hour: 10, title: '주간 계획 정리' }),
  ]);
  const visibleDates = useMemo(() => {
    if (activeView === 'day') {
      return [today];
    }

    return activeView === 'week'
      ? getWeekDates(today)
      : getMonthGridDates(today);
  }, [activeView]);

  const addEvent = (date = today, hour = 10) => {
    setEvents((currentEvents) => [
      ...currentEvents,
      createCalendarEvent({
        date,
        hour,
        title: `새 일정 ${currentEvents.length + 1}`,
      }),
    ]);
  };

  return (
    <section className="page-surface" aria-labelledby="calendar-heading">
      <PageHeader
        action={<Button onClick={() => addEvent()}>+ 일정 추가</Button>}
        description="주간 보기는 상단에 할 일 달성률을 요약하고, 아래에는 00시부터 24시까지 시간 단위로 일정을 배치합니다. 일정은 할 일 달성률에 포함되지 않습니다."
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

      {activeView === 'week' ? (
        <WeekCalendarView
          dates={visibleDates}
          events={events}
          onAddEvent={addEvent}
          summaries={sampleSummaries}
        />
      ) : (
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
      )}
    </section>
  );
}

function WeekCalendarView({
  dates,
  events,
  onAddEvent,
  summaries,
}: {
  dates: string[];
  events: DailyFlowCalendarEvent[];
  onAddEvent: (date?: string, hour?: number) => void;
  summaries: CalendarDaySummary[];
}) {
  const weekSummaries = dates
    .map((date) => summaries.find((summary) => summary.date === date))
    .filter((summary): summary is CalendarDaySummary => Boolean(summary));
  const averageRate = calculateAverageAchievementRate(weekSummaries);
  const completedCount = weekSummaries.reduce(
    (sum, summary) => sum + summary.completedTaskCount,
    0,
  );
  const plannedCount = weekSummaries.reduce(
    (sum, summary) => sum + summary.plannedTaskCount,
    0,
  );
  const weekEvents = events.filter((event) => {
    return dates.some((date) => eventFallsOnDate(event, date));
  });

  return (
    <div className="week-calendar" aria-label="주간 캘린더">
      <div className="week-summary-grid" aria-label="주간 요약">
        <CalendarSummaryCard
          label="주간 평균 달성률"
          value={
            averageRate === null
              ? '준비중'
              : `${Math.round(averageRate * 100)}%`
          }
        />
        <CalendarSummaryCard
          label="완료한 할 일"
          value={`${completedCount}/${plannedCount}`}
        />
        <CalendarSummaryCard
          label="등록된 일정"
          value={`${weekEvents.length}개`}
        />
      </div>

      <Card className="week-timeboard-card">
        <div
          className="week-timeboard"
          role="grid"
          aria-label="00시부터 24시까지 주간 일정표"
        >
          <div className="time-axis-header" />
          {dates.map((date) => (
            <div className="week-day-header" key={date} role="columnheader">
              <strong>{weekdayLabel(date)}</strong>
              <span>{formatCalendarDate(date)}</span>
              <small>
                {formatAchievement(
                  summaries.find((summary) => summary.date === date),
                )}
              </small>
            </div>
          ))}

          {hourSlots.map((hour) => (
            <WeekHourRow
              dates={dates}
              events={events}
              hour={hour}
              key={hour}
              onAddEvent={onAddEvent}
            />
          ))}
        </div>
      </Card>
    </div>
  );
}

function WeekHourRow({
  dates,
  events,
  hour,
  onAddEvent,
}: {
  dates: string[];
  events: DailyFlowCalendarEvent[];
  hour: number;
  onAddEvent: (date?: string, hour?: number) => void;
}) {
  return (
    <>
      <div className="time-axis-label" role="rowheader">
        {formatHourLabel(hour)}
      </div>
      {dates.map((date) => {
        const slotEvents = events.filter((event) => {
          return (
            eventFallsOnDate(event, date) && eventStartsAtHour(event, hour)
          );
        });

        return (
          <div
            className="week-time-slot"
            key={`${date}-${hour}`}
            role="gridcell"
          >
            {slotEvents.map((event) => (
              <div
                className="calendar-event calendar-event-timeblock"
                key={event.id}
              >
                <strong>{event.title}</strong>
                <span>
                  {formatEventTime(event.startsAt)}–
                  {formatEventTime(event.endsAt)}
                </span>
              </div>
            ))}
            <button
              aria-label={`${date} ${formatHourLabel(hour)} 일정 추가`}
              className="time-slot-add"
              onClick={() => onAddEvent(date, hour)}
              type="button"
            >
              +
            </button>
          </div>
        );
      })}
    </>
  );
}

function CalendarSummaryCard({
  label,
  value,
}: {
  label: string;
  value: string;
}) {
  return (
    <Card className="calendar-summary-card">
      <span>{label}</span>
      <strong>{value}</strong>
    </Card>
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

function formatHourLabel(hour: number) {
  return `${String(hour).padStart(2, '0')}:00`;
}
