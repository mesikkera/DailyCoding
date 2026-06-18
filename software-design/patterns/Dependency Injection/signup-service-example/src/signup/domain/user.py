from dataclasses import dataclass


@dataclass(frozen=True)
class User:
    # 도메인 모델은 애플리케이션의 핵심 개념을 표현합니다.
    # 이 예제에서는 회원을 이메일 하나로만 표현하지만,
    # 실제 서비스라면 id, 이름, 가입일, 상태 같은 값이 추가될 수 있습니다.
    #
    # frozen=True는 생성 후 값을 바꾸지 못하게 합니다.
    # 작은 예제에서는 필수는 아니지만, 도메인 객체를 안전한 값 객체처럼 다루는 데 도움이 됩니다.
    email: str
