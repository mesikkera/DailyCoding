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
  hour = 10,
  title,
}: {
  date: string;
  hour?: number;
  title: string;
}): DailyFlowCalendarEvent {
  const startsAt = `${date}T${String(hour).padStart(2, '0')}:00:00.000+09:00`;
  const endsAt = `${date}T${String(Math.min(hour + 1, 23)).padStart(2, '0')}:00:00.000+09:00`;

  return {
    id: `event-${crypto.randomUUID()}`,
    title: title.trim(),
    startsAt,
    endsAt,
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

export function eventStartsAtHour(event: DailyFlowCalendarEvent, hour: number) {
  return Number(event.startsAt.slice(11, 13)) === hour;
}

export function formatAchievement(summary: CalendarDaySummary | undefined) {
  if (!summary || summary.achievementRate === null) {
    return '달성률 준비중';
  }

  return `${Math.round(summary.achievementRate * 100)}%`;
}

export function calculateAverageAchievementRate(
  summaries: CalendarDaySummary[],
) {
  const validSummaries = summaries.filter(
    (summary) => summary.achievementRate !== null,
  );

  if (validSummaries.length === 0) {
    return null;
  }

  const total = validSummaries.reduce((sum, summary) => {
    return sum + (summary.achievementRate ?? 0);
  }, 0);

  return total / validSummaries.length;
}

function parseUtcDate(date: string) {
  return new Date(`${date}T00:00:00.000Z`);
}

function toDateKey(date: Date) {
  return date.toISOString().slice(0, 10);
}
