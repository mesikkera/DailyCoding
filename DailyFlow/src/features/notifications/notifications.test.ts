import { describe, expect, it } from 'vitest';

import {
  canSendTestNotification,
  createNotificationSubscriptionRecord,
  toggleNotificationSubscription,
} from './notifications';

describe('notifications domain', () => {
  it('creates an enabled browser push subscription only when granted', () => {
    const granted = createNotificationSubscriptionRecord({
      permission: 'granted',
      token: 'fcm-token',
      userAgent: 'vitest',
      userId: 'user-1',
    });
    const denied = createNotificationSubscriptionRecord({
      permission: 'denied',
      token: 'fcm-token',
      userAgent: 'vitest',
      userId: 'user-1',
    });

    expect(granted.enabled).toBe(true);
    expect(denied.enabled).toBe(false);
  });

  it('toggles a stored subscription', () => {
    const subscription = createNotificationSubscriptionRecord({
      permission: 'granted',
      token: 'fcm-token',
      userAgent: 'vitest',
      userId: 'user-1',
    });

    expect(toggleNotificationSubscription(subscription, false)).toMatchObject({
      enabled: false,
      token: 'fcm-token',
    });
  });

  it('allows test notification only when permission is granted and enabled', () => {
    expect(canSendTestNotification('granted', true)).toBe(true);
    expect(canSendTestNotification('granted', false)).toBe(false);
    expect(canSendTestNotification('denied', true)).toBe(false);
  });
});
