import { PageHeader } from '../../components/ui/PageHeader';
import { PlaceholderPanel } from '../../components/ui/PlaceholderPanel';

export function SettingsRoute() {
  return (
    <section className="page-surface" aria-labelledby="settings-heading">
      <PageHeader
        description="카테고리, 반복 루틴, 알림, 동기화 설정을 관리합니다."
        eyebrow="Settings"
        title="설정"
      />
      <PlaceholderPanel
        title="개인화 설정"
        description="초기에는 개인 계정 기준 설정을 만들고, 추후 협업 확장을 고려합니다."
        bullets={[
          '카테고리 생성/정렬/색상',
          '브라우저 푸시 알림 설정',
          '오프라인 동기화 상태와 계정 설정',
        ]}
      />
    </section>
  );
}
