import type { HTMLAttributes, ReactNode } from 'react';

interface CardProps extends HTMLAttributes<HTMLElement> {
  as?: 'article' | 'section' | 'div';
  children: ReactNode;
  tone?: 'default' | 'hero' | 'subtle';
}

export function Card({
  as: Component = 'article',
  children,
  className,
  tone = 'default',
  ...props
}: CardProps) {
  return (
    <Component
      className={['card', `card-${tone}`, className].filter(Boolean).join(' ')}
      {...props}
    >
      {children}
    </Component>
  );
}
