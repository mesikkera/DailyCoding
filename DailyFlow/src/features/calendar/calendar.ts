export type CalendarView = 'day' | 'week' | 'month';

export interface DailyFlowCalendarEvent {
  id: string;
  title: string;
  startsAt: string;
  endsAt: string;
  reminder: {
    enabled: boolean;
    minutesBefore: number;
  };
  deletedAt: string | null;
}

export interface CalendarDaySummary {
  date: string;
  plannedTaskCount: number;
  completedTaskCount: number;
  achievementRate: number | null;
}

export function createCalendarEvent({
  date,
  title,
}: {
  date: string;
  title: string;
}): DailyFlowCalendarEvent {
  return {
    id: `event-${crypto.randomUUID()}`,
    title: title.trim(),
    startsAt: `${date}T10:00:00.000+09:00`,
    endsAt: `${date}T11:00:00.000+09:00`,
    reminder: {
      enabled: true,
      minutesBefore: 10,
    },
    deletedAt: null,
  };
}

export function getWeekDates(anchorDate: string) {
  const anchor = parseUtcDate(anchorDate);
  const day = anchor.getUTCDay();
  const mondayOffset = day === 0 ? -6 : 1 - day;

  return Array.from({ length: 7 }, (_, index) => {
    const date = new Date(anchor);
    date.setUTCDate(anchor.getUTCDate() + mondayOffset + index);

    return toDateKey(date);
  });
}

export function getMonthGridDates(anchorDate: string) {
  const anchor = parseUtcDate(anchorDate);
  const firstOfMonth = new Date(
    Date.UTC(anchor.getUTCFullYear(), anchor.getUTCMonth(), 1),
  );
  const day = firstOfMonth.getUTCDay();
  const mondayOffset = day === 0 ? -6 : 1 - day;

  return Array.from({ length: 42 }, (_, index) => {
    const date = new Date(firstOfMonth);
    date.setUTCDate(firstOfMonth.getUTCDate() + mondayOffset + index);

    return toDateKey(date);
  });
}

export function getKoreanHolidayName(date: string) {
  const fixedHolidayMap: Record<string, string> = {
    '01-01': '신정',
    '03-01': '삼일절',
    '05-05': '어린이날',
    '06-06': '현충일',
    '08-15': '광복절',
    '10-03': '개천절',
    '10-09': '한글날',
    '12-25': '성탄절',
  };

  return fixedHolidayMap[date.slice(5)] ?? null;
}

export function eventFallsOnDate(event: DailyFlowCalendarEvent, date: string) {
  return event.deletedAt === null && event.startsAt.slice(0, 10) === date;
}

export function formatAchievement(summary: CalendarDaySummary | undefined) {
  if (!summary || summary.achievementRate === null) {
    return '달성률 준비중';
  }

  return `${Math.round(summary.achievementRate * 100)}%`;
}

function parseUtcDate(date: string) {
  return new Date(`${date}T00:00:00.000Z`);
}

function toDateKey(date: Date) {
  return date.toISOString().slice(0, 10);
}
