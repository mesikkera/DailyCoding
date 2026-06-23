import {
  addDoc,
  collection,
  doc,
  getDoc,
  getDocs,
  orderBy,
  query,
  serverTimestamp,
  updateDoc,
  where,
  type Firestore,
} from 'firebase/firestore';

import type { TaskRepository } from '../../features/tasks/taskRepository';
import {
  createLocalTask,
  type CreateTaskInput,
  type DailyFlowTask,
  type TaskStatus,
} from '../../features/tasks/task';

export class FirestoreTaskRepository implements TaskRepository {
  constructor(private readonly db: Firestore) {}

  async listTasksForDate(userId: string, scheduledDate: string) {
    const snapshot = await getDocs(
      query(
        collection(this.db, `users/${userId}/tasks`),
        where('scheduledDate', '==', scheduledDate),
        where('deletedAt', '==', null),
        orderBy('sortOrder', 'asc'),
      ),
    );

    return snapshot.docs.map((document) => {
      return { id: document.id, ...document.data() } as DailyFlowTask;
    });
  }

  async createTask(userId: string, input: CreateTaskInput) {
    const localTask = createLocalTask(input);
    const { id: _localId, ...taskData } = localTask;
    const docRef = await addDoc(collection(this.db, `users/${userId}/tasks`), {
      ...taskData,
      createdAt: serverTimestamp(),
      updatedAt: serverTimestamp(),
      clientUpdatedAt: serverTimestamp(),
    });

    return {
      ...localTask,
      id: docRef.id,
    };
  }

  async updateTaskStatus(userId: string, taskId: string, status: TaskStatus) {
    await updateDoc(doc(this.db, `users/${userId}/tasks/${taskId}`), {
      status,
      completedAt: status === 'completed' ? serverTimestamp() : null,
      updatedAt: serverTimestamp(),
      clientUpdatedAt: serverTimestamp(),
    });
  }

  async carryOverTask(userId: string, taskId: string, destinationDate: string) {
    const taskRef = doc(this.db, `users/${userId}/tasks/${taskId}`);
    const snapshot = await getDoc(taskRef);
    const task = snapshot.data() as DailyFlowTask | undefined;

    await updateDoc(taskRef, {
      scheduledDate: destinationDate,
      originalScheduledDate:
        task?.originalScheduledDate ?? task?.scheduledDate ?? null,
      carryOverCount: (task?.carryOverCount ?? 0) + 1,
      status: 'planned',
      completedAt: null,
      updatedAt: serverTimestamp(),
      clientUpdatedAt: serverTimestamp(),
    });
  }

  async softDeleteTask(userId: string, taskId: string) {
    await updateDoc(doc(this.db, `users/${userId}/tasks/${taskId}`), {
      deletedAt: serverTimestamp(),
      updatedAt: serverTimestamp(),
      clientUpdatedAt: serverTimestamp(),
    });
  }
}
