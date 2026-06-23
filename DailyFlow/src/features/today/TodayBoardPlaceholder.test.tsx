import { render, screen, within } from '@testing-library/react';
import userEvent from '@testing-library/user-event';
import { describe, expect, it } from 'vitest';

import { TodayBoardPlaceholder } from './TodayBoardPlaceholder';

describe('TodayBoardPlaceholder', () => {
  it('adds a planned task and updates planned count', async () => {
    const user = userEvent.setup();
    render(<TodayBoardPlaceholder />);

    await user.click(screen.getByRole('button', { name: '새 할 일' }));

    expect(screen.getByText('새 할 일 5')).toBeInTheDocument();
    expect(laneCount('예정')).toHaveTextContent('2');
    expect(screen.getByText('동기화 대기 1개')).toBeInTheDocument();
  });

  it('moves a task to completed and updates achievement rate', async () => {
    const user = userEvent.setup();
    render(<TodayBoardPlaceholder />);

    const taskActions = screen.getByLabelText('아침 루틴 정리 상태 변경');
    await user.click(within(taskActions).getByRole('button', { name: '완료' }));

    expect(laneCount('완료')).toHaveTextContent('2');
    expect(screen.getByText('67%')).toBeInTheDocument();
  });

  it('marks pending task changes as synced while online', async () => {
    const user = userEvent.setup();
    render(<TodayBoardPlaceholder />);

    await user.click(screen.getByRole('button', { name: '새 할 일' }));
    await user.click(screen.getByRole('button', { name: '동기화 완료 처리' }));

    expect(screen.getByText('동기화 완료')).toBeInTheDocument();
  });

  it('soft deletes a task from the visible board', async () => {
    const user = userEvent.setup();
    render(<TodayBoardPlaceholder />);

    const taskActions = screen.getByLabelText(
      '장기 보류 아이디어 정리 상태 변경',
    );
    await user.click(within(taskActions).getByRole('button', { name: '삭제' }));

    expect(
      screen.queryByText('장기 보류 아이디어 정리'),
    ).not.toBeInTheDocument();
    expect(laneCount('보류')).toHaveTextContent('0');
  });

  it('carries a task over to tomorrow and removes it from today lanes', async () => {
    const user = userEvent.setup();
    render(<TodayBoardPlaceholder />);

    const taskActions = screen.getByLabelText('아침 루틴 정리 상태 변경');
    await user.click(
      within(taskActions).getByRole('button', { name: '내일로 이월' }),
    );

    expect(screen.queryByText('아침 루틴 정리')).not.toBeInTheDocument();
    expect(laneCount('예정')).toHaveTextContent('0');
    expect(screen.getByText('동기화 대기 1개')).toBeInTheDocument();
  });
});

function laneCount(label: string) {
  const heading = screen.getByRole('heading', { name: label });
  const lane = heading.closest('section');

  if (!lane) {
    throw new Error(`Lane not found: ${label}`);
  }

  return within(lane).getByText(/^\d+$/);
}
