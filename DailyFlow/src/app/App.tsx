import { TodayBoardPlaceholder } from '../features/today/TodayBoardPlaceholder';

const navItems = ['Today', 'Calendar', 'Stats', 'Settings'];

export function App() {
  return (
    <div className="app-shell">
      <aside className="sidebar" aria-label="DailyFlow navigation">
        <div className="brand">
          <span className="brand-mark" aria-hidden="true">
            ◌
          </span>
          <span>DailyFlow</span>
        </div>
        <nav>
          {navItems.map((item) => (
            <a
              aria-current={item === 'Today' ? 'page' : undefined}
              className="nav-link"
              href={`#${item.toLowerCase()}`}
              key={item}
            >
              {item}
            </a>
          ))}
        </nav>
      </aside>

      <main className="main-surface">
        <TodayBoardPlaceholder />
      </main>
    </div>
  );
}
