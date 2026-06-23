import type { ChangeEvent, WheelEvent } from 'react';
import { useEffect, useMemo, useState } from 'react';

import { Badge } from '../../components/ui/Badge';
import { Button } from '../../components/ui/Button';
import { Card } from '../../components/ui/Card';
import { PageHeader } from '../../components/ui/PageHeader';
import {
  calculateAverageAchievementRate,
  createCalendarEvent,
  deleteCalendarEvent,
  eventFallsOnDate,
  eventStartsAtHour,
  formatAchievement,
  getKoreanHolidayName,
  getMonthGridDates,
  getWeekDates,
  renameCalendarEvent,
  type CalendarDaySummary,
  type CalendarView,
  type DailyFlowCalendarEvent,
} from '../../features/calendar/calendar';

const hourSlots = Array.from({ length: 24 }, (_, hour) => hour);

const viewOptions: Array<{ label: string; value: CalendarView }> = [
  { label: '일', value: 'day' },
  { label: '주', value: 'week' },
  { label: '월', value: 'month' },
];

export function CalendarRoute() {
  const today = useMemo(() => getLocalDateKey(new Date()), []);
  const currentWeekDates = useMemo(() => getWeekDates(today), [today]);
  const sampleSummaries = useMemo<CalendarDaySummary[]>(
    () => [
      {
        date: currentWeekDates[0],
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
        date: currentWeekDates[4],
        plannedTaskCount: 5,
        completedTaskCount: 4,
        achievementRate: 0.8,
      },
    ],
    [currentWeekDates, today],
  );
  const [activeView, setActiveView] = useState<CalendarView>('week');
  const [events, setEvents] = useState<DailyFlowCalendarEvent[]>([
    createCalendarEvent({ date: today, hour: 10, title: '주간 계획 정리' }),
  ]);
  const visibleDates = useMemo(() => {
    if (activeView === 'day') {
      return [today];
    }

    return activeView === 'week' ? currentWeekDates : getMonthGridDates(today);
  }, [activeView, currentWeekDates, today]);

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
  const renameEvent = (eventId: string, title: string) => {
    setEvents((currentEvents) =>
      currentEvents.map((event) =>
        event.id === eventId ? renameCalendarEvent(event, title) : event,
      ),
    );
  };
  const deleteEvent = (eventId: string) => {
    setEvents((currentEvents) =>
      currentEvents.map((event) =>
        event.id === eventId ? deleteCalendarEvent(event) : event,
      ),
    );
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
          onDeleteEvent={deleteEvent}
          onRenameEvent={renameEvent}
          summaries={sampleSummaries}
        />
      ) : (
        <div className={`calendar-grid calendar-grid-${activeView}`}>
          {visibleDates.map((date) => (
            <CalendarDayCell
              date={date}
              events={events.filter((event) => eventFallsOnDate(event, date))}
              key={date}
              onDeleteEvent={deleteEvent}
              onRenameEvent={renameEvent}
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
  onDeleteEvent,
  onRenameEvent,
  summaries,
}: {
  dates: string[];
  events: DailyFlowCalendarEvent[];
  onAddEvent: (date?: string, hour?: number) => void;
  onDeleteEvent: (eventId: string) => void;
  onRenameEvent: (eventId: string, title: string) => void;
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
  const handleTimeboardWheel = (event: WheelEvent<HTMLElement>) => {
    const scrollDelta =
      Math.abs(event.deltaX) > 0 ? event.deltaX : event.deltaY;

    if (scrollDelta === 0) {
      return;
    }

    event.preventDefault();
    event.currentTarget.scrollLeft += scrollDelta;
  };

  return (
    <div className="week-calendar" aria-label="주간 캘린더">
      <div className="week-range-heading" aria-label="이번 주 캘린더 범위">
        <span>이번 주</span>
        <strong>{formatWeekRange(dates)}</strong>
      </div>

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

      <Card
        aria-label="주간 시간표 스크롤 영역"
        className="week-timeboard-card"
        onWheel={handleTimeboardWheel}
        tabIndex={0}
      >
        <div
          className="week-timeboard"
          role="grid"
          aria-label="00시부터 24시까지 주간 일정표"
        >
          <div className="time-axis-header" aria-label="고정 시간축" />
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
              onDeleteEvent={onDeleteEvent}
              onRenameEvent={onRenameEvent}
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
  onDeleteEvent,
  onRenameEvent,
}: {
  dates: string[];
  events: DailyFlowCalendarEvent[];
  hour: number;
  onAddEvent: (date?: string, hour?: number) => void;
  onDeleteEvent: (eventId: string) => void;
  onRenameEvent: (eventId: string, title: string) => void;
}) {
  return (
    <>
      <div
        aria-label={`${formatHourLabel(hour)} 고정 시간축`}
        className="time-axis-label"
        role="rowheader"
      >
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
              <CalendarEventCard
                compact
                event={event}
                key={event.id}
                onDeleteEvent={onDeleteEvent}
                onRenameEvent={onRenameEvent}
              />
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
  onDeleteEvent,
  onRenameEvent,
  summary,
}: {
  date: string;
  events: DailyFlowCalendarEvent[];
  onDeleteEvent: (eventId: string) => void;
  onRenameEvent: (eventId: string, title: string) => void;
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
            <CalendarEventCard
              event={event}
              key={event.id}
              onDeleteEvent={onDeleteEvent}
              onRenameEvent={onRenameEvent}
            />
          ))
        ) : (
          <p>등록된 일정이 없습니다.</p>
        )}
      </div>
    </Card>
  );
}

function CalendarEventCard({
  compact = false,
  event,
  onDeleteEvent,
  onRenameEvent,
}: {
  compact?: boolean;
  event: DailyFlowCalendarEvent;
  onDeleteEvent: (eventId: string) => void;
  onRenameEvent: (eventId: string, title: string) => void;
}) {
  const [draftTitle, setDraftTitle] = useState(event.title);

  useEffect(() => {
    setDraftTitle(event.title);
  }, [event.title]);

  const handleTitleChange = (changeEvent: ChangeEvent<HTMLInputElement>) => {
    setDraftTitle(changeEvent.currentTarget.value);
  };
  const commitTitleChange = () => {
    const nextTitle =
      draftTitle.trim().length > 0 ? draftTitle.trim() : event.title;

    setDraftTitle(nextTitle);
    onRenameEvent(event.id, nextTitle);
  };

  return (
    <div
      className={`calendar-event ${compact ? 'calendar-event-timeblock' : ''}`}
    >
      <input
        aria-label={`${event.title} 제목 수정`}
        className="calendar-event-title-input"
        onBlur={commitTitleChange}
        onChange={handleTitleChange}
        onKeyDown={(keyboardEvent) => {
          if (keyboardEvent.key === 'Enter') {
            keyboardEvent.currentTarget.blur();
          }
        }}
        value={draftTitle}
      />
      <span>
        {formatEventTime(event.startsAt)}–{formatEventTime(event.endsAt)} · 알림{' '}
        {event.reminder.minutesBefore}분 전
      </span>
      <button
        aria-label={`${event.title} 삭제`}
        className="calendar-event-delete"
        onClick={() => onDeleteEvent(event.id)}
        type="button"
      >
        삭제
      </button>
    </div>
  );
}

function formatCalendarDate(date: string) {
  return new Intl.DateTimeFormat('ko-KR', {
    month: 'short',
    day: 'numeric',
  }).format(new Date(`${date}T00:00:00.000Z`));
}

function formatWeekRange(dates: string[]) {
  if (dates.length === 0) {
    return '';
  }

  const startDate = formatCalendarDate(dates[0]);
  const endDate = formatCalendarDate(dates[dates.length - 1]);

  return `${startDate}–${endDate}`;
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

function getLocalDateKey(date: Date) {
  const localMidnight = new Date(
    date.getTime() - date.getTimezoneOffset() * 60_000,
  );

  return localMidnight.toISOString().slice(0, 10);
}
