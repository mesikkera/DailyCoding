export type BrowserNotificationPermission =
  | 'default'
  | 'granted'
  | 'denied'
  | 'unsupported';

export interface NotificationSubscriptionRecord {
  id: string;
  userId: string;
  channel: 'browser_push';
  token: string;
  userAgent: string;
  permission: BrowserNotificationPermission;
  enabled: boolean;
  createdAt: string;
  updatedAt: string;
  deletedAt: string | null;
  schemaVersion: 1;
}

export function getBrowserNotificationPermission(): BrowserNotificationPermission {
  if (typeof Notification === 'undefined') {
    return 'unsupported';
  }

  return Notification.permission;
}

export async function requestBrowserNotificationPermission(): Promise<BrowserNotificationPermission> {
  if (typeof Notification === 'undefined') {
    return 'unsupported';
  }

  return Notification.requestPermission();
}

export function createNotificationSubscriptionRecord({
  permission,
  token,
  userAgent,
  userId,
}: {
  permission: BrowserNotificationPermission;
  token: string;
  userAgent: string;
  userId: string;
}): NotificationSubscriptionRecord {
  const now = new Date().toISOString();

  return {
    id: `browser-${userId}`,
    userId,
    channel: 'browser_push',
    token,
    userAgent,
    permission,
    enabled: permission === 'granted',
    createdAt: now,
    updatedAt: now,
    deletedAt: null,
    schemaVersion: 1,
  };
}

export function toggleNotificationSubscription(
  subscription: NotificationSubscriptionRecord,
  enabled: boolean,
): NotificationSubscriptionRecord {
  return {
    ...subscription,
    enabled,
    updatedAt: new Date().toISOString(),
  };
}

export function canSendTestNotification(
  permission: BrowserNotificationPermission,
  enabled: boolean,
) {
  return permission === 'granted' && enabled;
}
