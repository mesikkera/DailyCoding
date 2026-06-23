import type { User } from 'firebase/auth';
import { useCallback, useEffect, useMemo, useState } from 'react';

import type { AuthService } from '../../services/firebase/auth';
import type { BootstrapWriter } from './userBootstrap';
import { bootstrapUserProfile } from './userBootstrap';

export type AuthStatus =
  | 'unconfigured'
  | 'loading'
  | 'signed-out'
  | 'signed-in'
  | 'error';

interface UseAuthSessionInput {
  authService: AuthService | null;
  bootstrapWriter: BootstrapWriter | null;
}

export function useAuthSession({
  authService,
  bootstrapWriter,
}: UseAuthSessionInput) {
  const [status, setStatus] = useState<AuthStatus>(
    authService ? 'loading' : 'unconfigured',
  );
  const [user, setUser] = useState<User | null>(null);
  const [errorMessage, setErrorMessage] = useState<string | null>(null);

  useEffect(() => {
    if (!authService) {
      setStatus('unconfigured');
      setUser(null);
      return;
    }

    setStatus('loading');

    return authService.onAuthStateChanged((nextUser) => {
      setUser(nextUser);
      setStatus(nextUser ? 'signed-in' : 'signed-out');
    });
  }, [authService]);

  const bootstrap = useCallback(
    async (nextUser: User) => {
      if (!bootstrapWriter) {
        return;
      }

      await bootstrapUserProfile(
        {
          uid: nextUser.uid,
          displayName: nextUser.displayName,
          email: nextUser.email,
          photoURL: nextUser.photoURL,
        },
        bootstrapWriter,
      );
    },
    [bootstrapWriter],
  );

  const signInWithGoogle = useCallback(async () => {
    if (!authService) {
      return;
    }

    setErrorMessage(null);
    try {
      const nextUser = await authService.signInWithGoogle();
      await bootstrap(nextUser);
      setUser(nextUser);
      setStatus('signed-in');
    } catch (error) {
      setErrorMessage(readErrorMessage(error));
      setStatus('error');
    }
  }, [authService, bootstrap]);

  const signInWithApple = useCallback(async () => {
    if (!authService) {
      return;
    }

    setErrorMessage(null);
    try {
      const nextUser = await authService.signInWithApple();
      await bootstrap(nextUser);
      setUser(nextUser);
      setStatus('signed-in');
    } catch (error) {
      setErrorMessage(readErrorMessage(error));
      setStatus('error');
    }
  }, [authService, bootstrap]);

  const signOut = useCallback(async () => {
    if (!authService) {
      return;
    }

    setErrorMessage(null);
    try {
      await authService.signOut();
      setUser(null);
      setStatus('signed-out');
    } catch (error) {
      setErrorMessage(readErrorMessage(error));
      setStatus('error');
    }
  }, [authService]);

  return useMemo(
    () => ({
      errorMessage,
      signInWithApple,
      signInWithGoogle,
      signOut,
      status,
      user,
    }),
    [errorMessage, signInWithApple, signInWithGoogle, signOut, status, user],
  );
}

function readErrorMessage(error: unknown) {
  return error instanceof Error
    ? error.message
    : '인증 처리 중 오류가 발생했습니다.';
}
