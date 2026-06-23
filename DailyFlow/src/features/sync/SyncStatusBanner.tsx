import { Badge } from '../../components/ui/Badge';
import { Button } from '../../components/ui/Button';

interface SyncStatusBannerProps {
  isOnline: boolean;
  onMarkSynced: () => void;
  pendingCount: number;
}

export function SyncStatusBanner({
  isOnline,
  onMarkSynced,
  pendingCount,
}: SyncStatusBannerProps) {
  const stateLabel = isOnline ? '온라인' : '오프라인';
  const hasPendingTasks = pendingCount > 0;

  return (
    <aside
      aria-label="동기화 상태"
      className={`sync-banner ${isOnline ? 'sync-banner-online' : 'sync-banner-offline'}`}
    >
      <div>
        <Badge tone={isOnline ? 'success' : 'warning'}>{stateLabel}</Badge>
        <strong>{syncTitle(isOnline, pendingCount)}</strong>
        <p>{syncDescription(isOnline, pendingCount)}</p>
      </div>
      {hasPendingTasks ? (
        <Button disabled={!isOnline} onClick={onMarkSynced} variant="secondary">
          동기화 완료 처리
        </Button>
      ) : null}
    </aside>
  );
}

function syncTitle(isOnline: boolean, pendingCount: number) {
  if (!isOnline) {
    return pendingCount > 0
      ? `오프라인 변경 ${pendingCount}개 저장됨`
      : '오프라인에서도 오늘 보드를 볼 수 있습니다';
  }

  return pendingCount > 0 ? `동기화 대기 ${pendingCount}개` : '동기화 완료';
}

function syncDescription(isOnline: boolean, pendingCount: number) {
  if (!isOnline) {
    return pendingCount > 0
      ? '변경사항은 로컬에 보관되며 온라인 상태가 되면 서버 동기화 대상으로 표시됩니다.'
      : '네트워크가 없어도 할 일 조회와 상태 변경 흐름은 유지됩니다.';
  }

  return pendingCount > 0
    ? '온라인 상태입니다. 대기 중인 변경사항은 Firestore 동기화 큐로 처리될 예정입니다.'
    : '모든 오늘 보드 변경사항이 최신 상태입니다.';
}
