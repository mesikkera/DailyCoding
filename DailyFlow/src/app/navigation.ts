export type AppRoute = 'today' | 'calendar' | 'stats' | 'settings';

export interface NavItem {
  route: AppRoute;
  label: string;
  description: string;
}

export const navItems: NavItem[] = [
  {
    route: 'today',
    label: 'Today',
    description: '오늘의 상태 중심 칸반 보드',
  },
  {
    route: 'calendar',
    label: 'Calendar',
    description: '주간 기본 캘린더와 일정 관리',
  },
  {
    route: 'stats',
    label: 'Stats',
    description: '일별·주간·월간 달성률',
  },
  {
    route: 'settings',
    label: 'Settings',
    description: '카테고리, 알림, 동기화 설정',
  },
];

export function isAppRoute(value: string): value is AppRoute {
  return navItems.some((item) => item.route === value);
}
