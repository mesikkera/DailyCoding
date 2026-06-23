import { describe, expect, it } from 'vitest';

import {
  bootstrapUserProfile,
  createUserBootstrapOperations,
  type BootstrapWriteOperation,
} from './userBootstrap';

describe('createUserBootstrapOperations', () => {
  it('creates profile, settings, and default category writes', () => {
    const operations = createUserBootstrapOperations({
      uid: 'user-1',
      displayName: 'Daily User',
      email: 'daily@example.com',
      photoURL: null,
    });

    expect(operations.map((operation) => operation.path)).toEqual([
      'users/user-1',
      'users/user-1/settings/app',
      'users/user-1/categories/daily-life',
      'users/user-1/categories/daily-tasks',
      'users/user-1/categories/self-development',
      'users/user-1/categories/work',
    ]);
    expect(operations.every((operation) => operation.merge)).toBe(true);
  });

  it('keeps achievement defaults aligned with product rules', () => {
    const settingsOperation = createUserBootstrapOperations({
      uid: 'user-1',
      displayName: null,
      email: null,
      photoURL: null,
    })[1];

    expect(settingsOperation.data.achievement).toEqual({
      excludeOnHold: true,
      includeEvents: false,
    });
  });
});

describe('bootstrapUserProfile', () => {
  it('writes every bootstrap operation', async () => {
    const written: BootstrapWriteOperation[] = [];

    await bootstrapUserProfile(
      {
        uid: 'user-1',
        displayName: null,
        email: null,
        photoURL: null,
      },
      {
        async write(operation) {
          written.push(operation);
        },
      },
    );

    expect(written).toHaveLength(6);
    expect(written[0].path).toBe('users/user-1');
  });
});
