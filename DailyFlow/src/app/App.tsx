import { TodayBoardPlaceholder } from '../features/today/TodayBoardPlaceholder';
import { CalendarRoute } from './routes/CalendarRoute';
import { SettingsRoute } from './routes/SettingsRoute';
import { StatsRoute } from './routes/StatsRoute';
import { useHashRoute } from './useHashRoute';
import { navItems, type AppRoute } from './navigation';

export function App() {
  const activeRoute = useHashRoute();

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

      <main className="main-surface">{renderRoute(activeRoute)}</main>
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
