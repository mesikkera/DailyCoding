import {
  doc,
  serverTimestamp,
  setDoc,
  type Firestore,
} from 'firebase/firestore';

import type {
  BootstrapWriteOperation,
  BootstrapWriter,
} from '../../features/auth/userBootstrap';

export class FirestoreBootstrapWriter implements BootstrapWriter {
  constructor(private readonly db: Firestore) {}

  async write(operation: BootstrapWriteOperation) {
    const documentRef = doc(this.db, operation.path);
    const data = replaceIsoTimestamps(operation.data);

    await setDoc(documentRef, data, { merge: operation.merge ?? true });
  }
}

function replaceIsoTimestamps(data: Record<string, unknown>) {
  return Object.fromEntries(
    Object.entries(data).map(([key, value]) => {
      if (key === 'updatedAt' || key === 'clientUpdatedAt') {
        return [key, serverTimestamp()];
      }

      return [key, value];
    }),
  );
}
