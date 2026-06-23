import {
  doc,
  serverTimestamp,
  setDoc,
  type Firestore,
} from 'firebase/firestore';

import type { NotificationSubscriptionRecord } from '../../features/notifications/notifications';

export class FirestoreNotificationSubscriptionRepository {
  constructor(private readonly db: Firestore) {}

  async saveSubscription(subscription: NotificationSubscriptionRecord) {
    await setDoc(
      doc(
        this.db,
        `users/${subscription.userId}/notificationSubscriptions/${subscription.id}`,
      ),
      {
        ...subscription,
        createdAt: serverTimestamp(),
        updatedAt: serverTimestamp(),
      },
      { merge: true },
    );
  }
}
