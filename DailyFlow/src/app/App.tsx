import { useMemo } from 'react';

import { AuthPanel } from '../features/auth/AuthPanel';
import { TodayBoardPlaceholder } from '../features/today/TodayBoardPlaceholder';
import { CalendarRoute } from './routes/CalendarRoute';
import { SettingsRoute } from './routes/SettingsRoute';
import { StatsRoute } from './routes/StatsRoute';
import { useHashRoute } from './useHashRoute';
import { FirebaseAuthService } from '../services/firebase/auth';
import {
  getFirebaseConfigFromEnv,
  initializeDailyFlowFirebase,
} from '../services/firebase/app';
import { FirestoreBootstrapWriter } from '../services/firebase/firestoreWriter';
import { navItems, type AppRoute } from './navigation';

export function App() {
  const activeRoute = useHashRoute();
  const firebaseServices = useMemo(() => {
    const config = getFirebaseConfigFromEnv();

    return config ? initializeDailyFlowFirebase(config) : null;
  }, []);
  const authService = useMemo(() => {
    return firebaseServices
      ? new FirebaseAuthService(firebaseServices.auth)
      : null;
  }, [firebaseServices]);
  const bootstrapWriter = useMemo(() => {
    return firebaseServices
      ? new FirestoreBootstrapWriter(firebaseServices.db)
      : null;
  }, [firebaseServices]);

  return (
    <div className="app-shell">
      <aside className="sidebar" aria-label="DailyFlow navigation">
        <a className="brand" href="#today" aria-label="DailyFlow Today">
          <span className="brand-mark" aria-hidden="true">
            ◌
          </span>
          <span>DailyFlow</span>
        </a>
        <nav className="nav-list">
          {navItems.map((item) => (
            <a
              aria-current={item.route === activeRoute ? 'page' : undefined}
              className="nav-link"
              href={`#${item.route}`}
              key={item.route}
            >
              {item.label}
              <span className="nav-description">{item.description}</span>
            </a>
          ))}
        </nav>
      </aside>

      <main className="main-surface">
        <AuthPanel
          authService={authService}
          bootstrapWriter={bootstrapWriter}
        />
        {renderRoute(activeRoute)}
      </main>
    </div>
  );
}

function renderRoute(route: AppRoute) {
  switch (route) {
    case 'today':
      return <TodayBoardPlaceholder />;
    case 'calendar':
      return <CalendarRoute />;
    case 'stats':
      return <StatsRoute />;
    case 'settings':
      return <SettingsRoute />;
  }
}
