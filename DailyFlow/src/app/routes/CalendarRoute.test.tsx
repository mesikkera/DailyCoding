import { render, screen } from '@testing-library/react';
import userEvent from '@testing-library/user-event';
import { describe, expect, it } from 'vitest';

import { CalendarRoute } from './CalendarRoute';

describe('CalendarRoute', () => {
  it('loads week timetable view by default with achievement summary', () => {
    render(<CalendarRoute />);

    expect(screen.getByRole('button', { name: '주' })).toHaveAttribute(
      'aria-pressed',
      'true',
    );
    expect(screen.getByLabelText('주간 캘린더')).toBeInTheDocument();
    expect(screen.getByText('주간 평균 달성률')).toBeInTheDocument();
    expect(screen.getByText('00:00')).toBeInTheDocument();
    expect(screen.getByText('23:00')).toBeInTheDocument();
    expect(screen.getByText('주간 계획 정리')).toBeInTheDocument();
  });

  it('adds a calendar event from a weekly time slot', async () => {
    const user = userEvent.setup();
    render(<CalendarRoute />);

    const addButtons = screen.getAllByRole('button', {
      name: /09:00 일정 추가/,
    });
    await user.click(addButtons[0]);

    expect(screen.getByText('새 일정 2')).toBeInTheDocument();
  });

  it('switches day and month views', async () => {
    const user = userEvent.setup();
    render(<CalendarRoute />);

    await user.click(screen.getByRole('button', { name: '일' }));
    expect(screen.getByRole('button', { name: '일' })).toHaveAttribute(
      'aria-pressed',
      'true',
    );

    await user.click(screen.getByRole('button', { name: '월' }));
    expect(screen.getByRole('button', { name: '월' })).toHaveAttribute(
      'aria-pressed',
      'true',
    );
  });

  it('adds a default calendar event without changing task achievement copy', async () => {
    const user = userEvent.setup();
    render(<CalendarRoute />);

    await user.click(screen.getByRole('button', { name: '+ 일정 추가' }));

    expect(screen.getByText('새 일정 2')).toBeInTheDocument();
    expect(
      screen.getByText(/일정은 할 일 달성률에 포함되지 않습니다/),
    ).toBeInTheDocument();
  });
});
