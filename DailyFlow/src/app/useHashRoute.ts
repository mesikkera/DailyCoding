import { useEffect, useState } from 'react';

import { type AppRoute, isAppRoute } from './navigation';

function getRouteFromHash(): AppRoute {
  const hash = window.location.hash.replace('#', '');

  return isAppRoute(hash) ? hash : 'today';
}

export function useHashRoute() {
  const [route, setRoute] = useState<AppRoute>(() => getRouteFromHash());

  useEffect(() => {
    const handleHashChange = () => {
      setRoute(getRouteFromHash());
    };

    window.addEventListener('hashchange', handleHashChange);
    return () => window.removeEventListener('hashchange', handleHashChange);
  }, []);

  return route;
}
