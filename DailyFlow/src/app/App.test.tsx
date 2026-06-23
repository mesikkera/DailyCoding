import { render, screen } from '@testing-library/react';
import userEvent from '@testing-library/user-event';
import { afterEach, describe, expect, it } from 'vitest';

import { App } from './App';

afterEach(() => {
  window.location.hash = '';
});

describe('App', () => {
  it('renders the DailyFlow Today Board shell by default', () => {
    render(<App />);

    expect(
      screen.getByRole('link', { name: 'DailyFlow Today' }),
    ).toBeInTheDocument();
    expect(
      screen.getByRole('heading', { name: '오늘의 흐름' }),
    ).toBeInTheDocument();
    expect(
      screen.getByRole('button', { name: '+ 할 일 추가' }),
    ).toBeInTheDocument();
  });

  it('switches placeholder surfaces through hash navigation', async () => {
    const user = userEvent.setup();
    render(<App />);

    await user.click(screen.getByRole('link', { name: /Calendar/ }));
    expect(screen.getByRole('heading', { name: '캘린더' })).toBeInTheDocument();

    await user.click(screen.getByRole('link', { name: /Stats/ }));
    expect(screen.getByRole('heading', { name: '통계' })).toBeInTheDocument();

    await user.click(screen.getByRole('link', { name: /Settings/ }));
    expect(screen.getByRole('heading', { name: '설정' })).toBeInTheDocument();
  });
});
