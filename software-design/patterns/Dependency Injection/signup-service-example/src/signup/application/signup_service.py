from signup.application.ports import EmailSender, UserRepository
from signup.domain.user import User


class DuplicateEmailError(ValueError):
    # 중복 이메일이라는 도메인/유스케이스 수준의 실패를 표현합니다.
    # 단순히 ValueError를 직접 던지는 것보다, 호출하는 쪽에서 실패 원인을 구분하기 쉽습니다.
    pass


class SignUpService:
    # SignUpService는 회원가입 유스케이스를 담당하는 애플리케이션 서비스입니다.
    # 핵심은 이 클래스가 InMemoryUserRepository나 ConsoleEmailSender를 직접 만들지 않는다는 점입니다.
    # 필요한 역할은 생성자로 전달받고, 전달받은 객체가 Protocol을 만족하기만 하면 됩니다.
    def __init__(
        self,
        user_repository: UserRepository,
        email_sender: EmailSender,
    ) -> None:
        # 생성자 주입(Constructor Injection)을 사용하는 지점입니다.
        # 객체가 정상 동작하기 위해 반드시 필요한 의존성을 생성 시점에 받습니다.
        # 이렇게 하면 의존성이 빠진 불완전한 SignUpService가 만들어지는 일을 줄일 수 있습니다.
        self.user_repository = user_repository
        self.email_sender = email_sender

    def sign_up(self, email: str) -> User:
        # 유스케이스의 첫 번째 규칙은 중복 가입 방지입니다.
        # 저장소가 어떤 방식으로 데이터를 찾는지는 서비스의 관심사가 아닙니다.
        if self.user_repository.exists(email):
            raise DuplicateEmailError("이미 가입된 이메일입니다.")

        # 도메인 객체를 생성합니다.
        # 현재 User는 이메일만 가진 단순한 값 객체이지만, 나중에 검증 규칙이 늘어나도 이 위치가 기준점이 됩니다.
        user = User(email=email)

        # 저장과 알림은 서로 다른 외부 의존성입니다.
        # 서비스는 "저장한다", "환영 이메일을 보낸다"는 흐름만 알고,
        # 실제 저장 방식과 전송 방식은 주입된 구현체에게 위임합니다.
        self.user_repository.save(user.email)
        self.email_sender.send_welcome(user.email)

        # 호출자가 가입된 사용자를 이어서 사용할 수 있도록 결과를 반환합니다.
        return user
