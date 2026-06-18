from typing import Protocol


class UserRepository(Protocol):
    # Protocol은 "이 역할을 수행하려면 어떤 메서드를 가져야 하는가"를 표현합니다.
    # SignUpService는 구체 클래스가 아니라 이 역할에 의존합니다.
    # 덕분에 메모리 저장소, 파일 저장소, 데이터베이스 저장소를 같은 방식으로 교체할 수 있습니다.
    def exists(self, email: str) -> bool:
        # 이메일이 이미 저장되어 있는지 확인합니다.
        # 서비스는 중복 가입을 막기 위해 이 메서드만 필요로 합니다.
        ...

    def save(self, email: str) -> None:
        # 회원가입이 성공한 이메일을 저장합니다.
        # 저장 방식은 구현체가 결정하므로, 서비스는 메모리인지 DB인지 알 필요가 없습니다.
        ...


class EmailSender(Protocol):
    # 이메일 전송 역할도 Protocol로 분리합니다.
    # 실제 실행에서는 콘솔 출력 구현체를 쓰고, 테스트에서는 Fake 구현체를 주입할 수 있습니다.
    def send_welcome(self, email: str) -> None:
        # 회원가입 성공 후 환영 메시지를 보냅니다.
        # 외부 API 호출처럼 느리거나 불안정한 작업은 테스트에서 Fake로 대체하기 좋습니다.
        ...
