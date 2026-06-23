import { useState } from 'react';

import { Badge } from '../../components/ui/Badge';
import { Button } from '../../components/ui/Button';
import { Card } from '../../components/ui/Card';
import { PageHeader } from '../../components/ui/PageHeader';
import {
  canSendTestNotification,
  createNotificationSubscriptionRecord,
  getBrowserNotificationPermission,
  requestBrowserNotificationPermission,
  toggleNotificationSubscription,
  type BrowserNotificationPermission,
  type NotificationSubscriptionRecord,
} from '../../features/notifications/notifications';

const demoUserId = 'local-demo-user';

export function SettingsRoute() {
  const [permission, setPermission] = useState<BrowserNotificationPermission>(
    () => getBrowserNotificationPermission(),
  );
  const [subscription, setSubscription] =
    useState<NotificationSubscriptionRecord | null>(null);
  const [lastTestMessage, setLastTestMessage] = useState<string | null>(null);

  const requestPermission = async () => {
    const nextPermission = await requestBrowserNotificationPermission();
    setPermission(nextPermission);

    setSubscription(
      createNotificationSubscriptionRecord({
        permission: nextPermission,
        token: 'pending-fcm-token',
        userAgent:
          typeof navigator === 'undefined' ? 'unknown' : navigator.userAgent,
        userId: demoUserId,
      }),
    );
  };

  const togglePush = () => {
    setSubscription((currentSubscription) => {
      if (!currentSubscription) {
        return createNotificationSubscriptionRecord({
          permission,
          token: 'pending-fcm-token',
          userAgent:
            typeof navigator === 'undefined' ? 'unknown' : navigator.userAgent,
          userId: demoUserId,
        });
      }

      return toggleNotificationSubscription(
        currentSubscription,
        !currentSubscription.enabled,
      );
    });
  };

  const sendTestNotification = () => {
    if (!canSendTestNotification(permission, subscription?.enabled ?? false)) {
      setLastTestMessage('권한 허용과 브라우저 푸시 활성화가 필요합니다.');
      return;
    }

    if (typeof Notification !== 'undefined') {
      new Notification('DailyFlow 테스트 알림', {
        body: '할 일/일정 리마인더가 이 흐름으로 전달됩니다.',
      });
    }

    setLastTestMessage('테스트 알림을 요청했습니다.');
  };

  return (
    <section className="page-surface" aria-labelledby="settings-heading">
      <PageHeader
        description="카테고리, 반복 루틴, 알림, 동기화 설정을 관리합니다."
        eyebrow="Settings"
        title="설정"
      />

      <Card className="settings-card">
        <header>
          <div>
            <h2>브라우저 푸시 알림</h2>
            <p>
              이메일·텔레그램보다 먼저 브라우저 푸시를 MVP 알림 채널로
              설정합니다.
            </p>
          </div>
          <Badge tone={permissionTone(permission)}>
            {permissionLabel(permission)}
          </Badge>
        </header>

        <div className="notification-settings-grid">
          <SettingMetric
            label="구독 저장 위치"
            value="notificationSubscriptions"
          />
          <SettingMetric
            label="FCM 토큰"
            value={subscription ? '저장 대기' : '미생성'}
          />
          <SettingMetric
            label="브라우저 푸시"
            value={subscription?.enabled ? '활성화' : '비활성화'}
          />
        </div>

        <div className="settings-actions">
          <Button onClick={requestPermission}>알림 권한 요청</Button>
          <Button onClick={togglePush} variant="secondary">
            브라우저 푸시 {subscription?.enabled ? '끄기' : '켜기'}
          </Button>
          <Button onClick={sendTestNotification} variant="ghost">
            테스트 알림 보내기
          </Button>
        </div>

        {lastTestMessage ? (
          <p className="settings-note">{lastTestMessage}</p>
        ) : null}
      </Card>
    </section>
  );
}

function SettingMetric({ label, value }: { label: string; value: string }) {
  return (
    <div className="setting-metric">
      <span>{label}</span>
      <strong>{value}</strong>
    </div>
  );
}

function permissionLabel(permission: BrowserNotificationPermission) {
  switch (permission) {
    case 'default':
      return '권한 미선택';
    case 'granted':
      return '권한 허용';
    case 'denied':
      return '권한 거부';
    case 'unsupported':
      return '미지원';
  }
}

function permissionTone(permission: BrowserNotificationPermission) {
  switch (permission) {
    case 'granted':
      return 'success';
    case 'denied':
    case 'unsupported':
      return 'muted';
    case 'default':
      return 'warning';
  }
}
