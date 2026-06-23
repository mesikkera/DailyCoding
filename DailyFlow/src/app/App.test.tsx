import { render, screen } from '@testing-library/react';
import { describe, expect, it } from 'vitest';

import { App } from './App';

describe('App', () => {
  it('renders the DailyFlow Today Board shell', () => {
    render(<App />);

    expect(screen.getByText('DailyFlow')).toBeInTheDocument();
    expect(
      screen.getByRole('heading', { name: '오늘의 흐름' }),
    ).toBeInTheDocument();
    expect(
      screen.getByRole('button', { name: '+ 할 일 추가' }),
    ).toBeInTheDocument();
  });
});
