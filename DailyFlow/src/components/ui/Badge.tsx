import type { HTMLAttributes, ReactNode } from 'react';

interface BadgeProps extends HTMLAttributes<HTMLSpanElement> {
  children: ReactNode;
  tone?:
    | 'neutral'
    | 'primary'
    | 'success'
    | 'warning'
    | 'muted'
    | 'priority-high'
    | 'priority-normal'
    | 'priority-low';
}

export function Badge({
  children,
  className,
  tone = 'neutral',
  ...props
}: BadgeProps) {
  return (
    <span
      className={['badge', `badge-${tone}`, className]
        .filter(Boolean)
        .join(' ')}
      {...props}
    >
      {children}
    </span>
  );
}
