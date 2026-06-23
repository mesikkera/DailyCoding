import { Card } from './Card';

interface PlaceholderPanelProps {
  title: string;
  description: string;
  bullets: string[];
}

export function PlaceholderPanel({
  bullets,
  description,
  title,
}: PlaceholderPanelProps) {
  return (
    <Card as="section" className="placeholder-panel">
      <p className="eyebrow">Planned Surface</p>
      <h2>{title}</h2>
      <p className="muted">{description}</p>
      <ul>
        {bullets.map((bullet) => (
          <li key={bullet}>{bullet}</li>
        ))}
      </ul>
    </Card>
  );
}
