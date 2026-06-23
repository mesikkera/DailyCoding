import { render, screen } from '@testing-library/react';
import userEvent from '@testing-library/user-event';
import { describe, expect, it } from 'vitest';

import { CalendarRoute } from './CalendarRoute';

describe('CalendarRoute', () => {
  it('loads week view by default', () => {
    render(<CalendarRoute />);

    expect(screen.getByRole('button', { name: '주' })).toHaveAttribute(
      'aria-pressed',
      'true',
    );
    expect(screen.getByText('주간 계획 정리')).toBeInTheDocument();
    expect(screen.getAllByText(/달성률/).length).toBeGreaterThan(0);
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

  it('adds a calendar event without changing task achievement copy', async () => {
    const user = userEvent.setup();
    render(<CalendarRoute />);

    await user.click(screen.getByRole('button', { name: '+ 일정 추가' }));

    expect(screen.getByText('새 일정 2')).toBeInTheDocument();
    expect(
      screen.getByText(/일정은 할 일 달성률에 포함되지 않습니다/),
    ).toBeInTheDocument();
  });
});
