export interface DefaultCategory {
  id: string;
  name: string;
  color: string;
  order: number;
}

export const defaultCategories: DefaultCategory[] = [
  { id: 'daily-life', name: '오늘의 생활', color: '#34c759', order: 10 },
  { id: 'daily-tasks', name: '오늘의 할 일', color: '#007aff', order: 20 },
  {
    id: 'self-development',
    name: '오늘의 자기 계발',
    color: '#af52de',
    order: 30,
  },
  { id: 'work', name: '오늘의 업무', color: '#ff9f0a', order: 40 },
];

export const defaultAppSettings = {
  categoryOrder: defaultCategories.map((category) => category.id),
  defaultTaskStatus: 'planned',
  defaultTaskPriority: 'normal',
  carryOver: {
    enabled: true,
    defaultTarget: 'tomorrow',
  },
  achievement: {
    excludeOnHold: true,
    includeEvents: false,
  },
  notifications: {
    browserPushEnabled: false,
  },
  calendar: {
    defaultView: 'week',
    showKoreanHolidays: true,
  },
} as const;
