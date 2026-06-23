import { describe, expect, it } from 'vitest';

import {
  calculateAverageAchievementRate,
  createCalendarEvent,
  eventFallsOnDate,
  eventStartsAtHour,
  formatAchievement,
  getKoreanHolidayName,
  getMonthGridDates,
  getWeekDates,
} from './calendar';

describe('calendar domain', () => {
  it('builds week dates from Monday to Sunday', () => {
    expect(getWeekDates('2026-06-23')).toEqual([
      '2026-06-22',
      '2026-06-23',
      '2026-06-24',
      '2026-06-25',
      '2026-06-26',
      '2026-06-27',
      '2026-06-28',
    ]);
  });

  it('builds a 6 week month grid', () => {
    const grid = getMonthGridDates('2026-06-23');

    expect(grid).toHaveLength(42);
    expect(grid[0]).toBe('2026-06-01');
    expect(grid[41]).toBe('2026-07-12');
  });

  it('creates event reminders without changing achievement formatting', () => {
    const event = createCalendarEvent({
      date: '2026-06-23',
      hour: 14,
      title: ' 주간 계획 ',
    });

    expect(event.title).toBe('주간 계획');
    expect(event.startsAt).toContain('T14:00:00.000+09:00');
    expect(event.reminder).toEqual({ enabled: true, minutesBefore: 10 });
    expect(eventFallsOnDate(event, '2026-06-23')).toBe(true);
    expect(eventStartsAtHour(event, 14)).toBe(true);
    expect(formatAchievement(undefined)).toBe('달성률 준비중');
  });

  it('calculates weekly average achievement from visible day summaries', () => {
    expect(
      calculateAverageAchievementRate([
        {
          date: '2026-06-22',
          plannedTaskCount: 2,
          completedTaskCount: 1,
          achievementRate: 0.5,
        },
        {
          date: '2026-06-23',
          plannedTaskCount: 4,
          completedTaskCount: 3,
          achievementRate: 0.75,
        },
      ]),
    ).toBe(0.625);
  });

  it('returns fixed Korean holiday names', () => {
    expect(getKoreanHolidayName('2026-08-15')).toBe('광복절');
    expect(getKoreanHolidayName('2026-06-23')).toBeNull();
  });
});
