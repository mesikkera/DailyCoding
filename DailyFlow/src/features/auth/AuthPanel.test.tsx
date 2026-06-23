import { render, screen } from '@testing-library/react';
import userEvent from '@testing-library/user-event';
import type { User } from 'firebase/auth';
import { describe, expect, it, vi } from 'vitest';

import type { AuthService } from '../../services/firebase/auth';
import { AuthPanel } from './AuthPanel';

function createFakeUser(overrides: Partial<User> = {}): User {
  return {
    uid: 'user-1',
    displayName: 'Daily User',
    email: 'daily@example.com',
    photoURL: null,
    ...overrides,
  } as User;
}

describe('AuthPanel', () => {
  it('explains missing Firebase configuration', () => {
    render(<AuthPanel authService={null} bootstrapWriter={null} />);

    expect(screen.getByText('설정 필요')).toBeInTheDocument();
    expect(
      screen.getByRole('button', { name: 'Google 로그인' }),
    ).toBeDisabled();
    expect(screen.getByRole('button', { name: 'Apple 로그인' })).toBeDisabled();
  });

  it('signs in with Google and bootstraps the user', async () => {
    const user = userEvent.setup();
    const firebaseUser = createFakeUser();
    const authService: AuthService = {
      onAuthStateChanged(callback) {
        callback(null);
        return () => undefined;
      },
      signInWithGoogle: vi.fn().mockResolvedValue(firebaseUser),
      signInWithApple: vi.fn(),
      signOut: vi.fn(),
    };
    const write = vi.fn().mockResolvedValue(undefined);

    render(<AuthPanel authService={authService} bootstrapWriter={{ write }} />);

    await user.click(screen.getByRole('button', { name: 'Google 로그인' }));

    expect(authService.signInWithGoogle).toHaveBeenCalledOnce();
    expect(write).toHaveBeenCalledTimes(6);
    expect(await screen.findByText('Daily User')).toBeInTheDocument();
  });
});
