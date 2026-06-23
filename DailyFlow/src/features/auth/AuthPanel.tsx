import { Badge } from '../../components/ui/Badge';
import { Button } from '../../components/ui/Button';
import type { AuthStatus } from './useAuthSession';
import { useAuthSession } from './useAuthSession';
import type { AuthService } from '../../services/firebase/auth';
import type { BootstrapWriter } from './userBootstrap';

interface AuthPanelProps {
  authService: AuthService | null;
  bootstrapWriter: BootstrapWriter | null;
}

export function AuthPanel({ authService, bootstrapWriter }: AuthPanelProps) {
  const session = useAuthSession({ authService, bootstrapWriter });

  return (
    <section className="auth-panel" aria-label="계정 상태">
      <div>
        <Badge tone={statusTone(session.status)}>
          {statusLabel(session.status)}
        </Badge>
        <p className="auth-title">
          {session.user?.displayName ?? 'DailyFlow 계정'}
        </p>
        <p className="auth-description">
          {session.user?.email ?? authDescription(session.status)}
        </p>
        {session.errorMessage ? (
          <p className="auth-error" role="alert">
            {session.errorMessage}
          </p>
        ) : null}
      </div>

      <div className="auth-actions">
        {session.user ? (
          <Button onClick={session.signOut} variant="secondary">
            로그아웃
          </Button>
        ) : (
          <>
            <Button
              disabled={session.status === 'unconfigured'}
              onClick={session.signInWithGoogle}
              variant="secondary"
            >
              Google 로그인
            </Button>
            <Button
              disabled={session.status === 'unconfigured'}
              onClick={session.signInWithApple}
              variant="ghost"
            >
              Apple 로그인
            </Button>
          </>
        )}
      </div>
    </section>
  );
}

function statusLabel(status: AuthStatus) {
  switch (status) {
    case 'unconfigured':
      return '설정 필요';
    case 'loading':
      return '확인 중';
    case 'signed-out':
      return '로그아웃';
    case 'signed-in':
      return '동기화 준비';
    case 'error':
      return '오류';
  }
}

function statusTone(status: AuthStatus) {
  switch (status) {
    case 'signed-in':
      return 'success';
    case 'error':
      return 'warning';
    case 'unconfigured':
      return 'muted';
    case 'loading':
    case 'signed-out':
      return 'primary';
  }
}

function authDescription(status: AuthStatus) {
  switch (status) {
    case 'unconfigured':
      return '.env에 Firebase 웹 앱 설정을 추가하면 소셜 로그인을 사용할 수 있습니다.';
    case 'loading':
      return '현재 로그인 상태를 확인하고 있습니다.';
    case 'signed-out':
      return 'Google 또는 Apple 계정으로 로그인해 데이터를 동기화합니다.';
    case 'signed-in':
      return '계정 기반 동기화가 준비되었습니다.';
    case 'error':
      return '로그인 상태를 다시 확인해주세요.';
  }
}
