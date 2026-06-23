import { defaultAppSettings, defaultCategories } from '../settings/defaults';

export interface AuthenticatedUserProfile {
  uid: string;
  displayName: string | null;
  email: string | null;
  photoURL: string | null;
}

export interface BootstrapWriteOperation {
  path: string;
  data: Record<string, unknown>;
  merge?: boolean;
}

export interface BootstrapWriter {
  write(operation: BootstrapWriteOperation): Promise<void>;
}

export function createUserBootstrapOperations(
  user: AuthenticatedUserProfile,
): BootstrapWriteOperation[] {
  const now = new Date().toISOString();

  return [
    {
      path: `users/${user.uid}`,
      merge: true,
      data: {
        displayName: user.displayName,
        email: user.email,
        photoURL: user.photoURL,
        locale: 'ko-KR',
        timezone: 'Asia/Seoul',
        defaultCalendarView: 'week',
        updatedAt: now,
      },
    },
    {
      path: `users/${user.uid}/settings/app`,
      merge: true,
      data: {
        ...defaultAppSettings,
        updatedAt: now,
      },
    },
    ...defaultCategories.map((category) => ({
      path: `users/${user.uid}/categories/${category.id}`,
      merge: true,
      data: {
        name: category.name,
        color: category.color,
        order: category.order,
        archivedAt: null,
        deletedAt: null,
        schemaVersion: 1,
        updatedAt: now,
        clientUpdatedAt: now,
      },
    })),
  ];
}

export async function bootstrapUserProfile(
  user: AuthenticatedUserProfile,
  writer: BootstrapWriter,
) {
  const operations = createUserBootstrapOperations(user);

  await Promise.all(
    operations.map((operation) => {
      return writer.write(operation);
    }),
  );
}
