import { render, screen } from '@testing-library/react';
import { describe, expect, it } from 'vitest';

import { StatsRoute } from './StatsRoute';

describe('StatsRoute', () => {
  it('shows daily, weekly, and monthly achievement summaries', () => {
    render(<StatsRoute />);

    expect(screen.getByRole('heading', { name: '통계' })).toBeInTheDocument();
    expect(screen.getByText('오늘 달성률')).toBeInTheDocument();
    expect(screen.getByText('주간 평균')).toBeInTheDocument();
    expect(screen.getByText('월간 평균')).toBeInTheDocument();
  });

  it('explains task-only stats and on-hold exclusion', () => {
    render(<StatsRoute />);

    expect(screen.getByText('Task-only')).toBeInTheDocument();
    expect(screen.getAllByText('보류 제외').length).toBeGreaterThan(0);
    expect(
      screen.getByText(/보류와 일정 이벤트는 통계에서 제외됩니다/),
    ).toBeInTheDocument();
  });
});
