import pytest

from signup.application.signup_service import DuplicateEmailError, SignUpService


class FakeUserRepository:
    # 테스트용 저장소입니다.
    # 실제 InMemoryUserRepository를 그대로 써도 되지만,
    # 테스트 안에 Fake를 두면 "서비스가 필요로 하는 계약"이 무엇인지 더 잘 드러납니다.
    def __init__(self) -> None:
        self.emails: set[str] = set()

    def exists(self, email: str) -> bool:
        # SignUpService가 중복 이메일을 확인할 수 있도록 UserRepository 역할을 흉내 냅니다.
        return email in self.emails

    def save(self, email: str) -> None:
        # 저장 요청이 들어왔는지 테스트에서 확인할 수 있도록 메모리에 기록합니다.
        self.emails.add(email)


class FakeEmailSender:
    # 테스트용 이메일 전송기입니다.
    # 실제 이메일을 보내지 않고, 어떤 이메일로 환영 메시지를 보내려 했는지만 기록합니다.
    def __init__(self) -> None:
        self.sent_welcome_emails: list[str] = []

    def send_welcome(self, email: str) -> None:
        # 외부 시스템을 호출하는 대신 리스트에 기록합니다.
        # 이것이 DI가 테스트를 쉽게 만드는 대표적인 장면입니다.
        self.sent_welcome_emails.append(email)


def test_sign_up_saves_user_and_sends_welcome_email() -> None:
    # given: 서비스에 실제 구현체가 아니라 Fake 구현체를 주입합니다.
    # 테스트는 외부 저장소나 이메일 서버 없이도 유스케이스 흐름만 검증할 수 있습니다.
    repository = FakeUserRepository()
    email_sender = FakeEmailSender()
    service = SignUpService(repository, email_sender)

    # when: 회원가입 유스케이스를 실행합니다.
    user = service.sign_up("dev@example.com")

    # then: 사용자 저장과 환영 이메일 전송이 모두 일어났는지 확인합니다.
    assert user.email == "dev@example.com"
    assert repository.exists("dev@example.com")
    assert email_sender.sent_welcome_emails == ["dev@example.com"]


def test_sign_up_fails_when_email_already_exists() -> None:
    # given: 이미 같은 이메일이 저장된 상태를 만듭니다.
    repository = FakeUserRepository()
    repository.save("dev@example.com")
    email_sender = FakeEmailSender()
    service = SignUpService(repository, email_sender)

    # when & then: 같은 이메일로 가입하면 명시적인 예외가 발생해야 합니다.
    with pytest.raises(DuplicateEmailError, match="이미 가입된 이메일입니다"):
        service.sign_up("dev@example.com")

    # 실패한 가입에서는 환영 이메일이 발송되면 안 됩니다.
    assert email_sender.sent_welcome_emails == []
