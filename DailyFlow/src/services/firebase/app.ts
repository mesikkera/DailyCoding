import { getApps, initializeApp, type FirebaseApp } from 'firebase/app';

export interface DailyFlowFirebaseConfig {
  apiKey: string;
  authDomain: string;
  projectId: string;
  storageBucket: string;
  messagingSenderId: string;
  appId: string;
}

export function getFirebaseConfigFromEnv(): DailyFlowFirebaseConfig | null {
  const config = {
    apiKey: import.meta.env.VITE_FIREBASE_API_KEY,
    authDomain: import.meta.env.VITE_FIREBASE_AUTH_DOMAIN,
    projectId: import.meta.env.VITE_FIREBASE_PROJECT_ID,
    storageBucket: import.meta.env.VITE_FIREBASE_STORAGE_BUCKET,
    messagingSenderId: import.meta.env.VITE_FIREBASE_MESSAGING_SENDER_ID,
    appId: import.meta.env.VITE_FIREBASE_APP_ID,
  };

  return Object.values(config).every(Boolean)
    ? (config as DailyFlowFirebaseConfig)
    : null;
}

export function initializeDailyFlowFirebase(
  config: DailyFlowFirebaseConfig,
): FirebaseApp {
  return getApps()[0] ?? initializeApp(config);
}
