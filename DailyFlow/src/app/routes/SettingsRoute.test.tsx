import { render, screen } from '@testing-library/react';
import userEvent from '@testing-library/user-event';
import { describe, expect, it } from 'vitest';

import { SettingsRoute } from './SettingsRoute';

describe('SettingsRoute', () => {
  it('shows browser push notification settings', () => {
    render(<SettingsRoute />);

    expect(screen.getByRole('heading', { name: '설정' })).toBeInTheDocument();
    expect(screen.getByText('브라우저 푸시 알림')).toBeInTheDocument();
    expect(screen.getByText('notificationSubscriptions')).toBeInTheDocument();
  });

  it('records unsupported permission state and blocks test notifications', async () => {
    const user = userEvent.setup();
    render(<SettingsRoute />);

    await user.click(screen.getByRole('button', { name: '알림 권한 요청' }));
    await user.click(
      screen.getByRole('button', { name: '테스트 알림 보내기' }),
    );

    expect(screen.getByText('미지원')).toBeInTheDocument();
    expect(
      screen.getByText('권한 허용과 브라우저 푸시 활성화가 필요합니다.'),
    ).toBeInTheDocument();
  });
});
