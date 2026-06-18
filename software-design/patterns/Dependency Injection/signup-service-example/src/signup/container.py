from signup.application.signup_service import SignUpService
from signup.infrastructure.console_email_sender import ConsoleEmailSender
from signup.infrastructure.in_memory_user_repository import InMemoryUserRepository


def create_signup_service() -> SignUpService:
    # 이 함수는 아주 작은 DI 컨테이너 또는 composition root 역할을 합니다.
    # 애플리케이션에서 사용할 구체 구현체를 여기서 선택하고 연결합니다.
    #
    # 중요한 점은 SignUpService 내부가 아니라 이 바깥쪽 코드에서 구현체를 결정한다는 것입니다.
    # 그래서 나중에 InMemoryUserRepository를 JsonFileUserRepository로 바꾸더라도
    # SignUpService 코드는 그대로 둘 수 있습니다.
    user_repository = InMemoryUserRepository()
    email_sender = ConsoleEmailSender()

    # 생성된 구현체를 SignUpService에 주입합니다.
    # 이 한 줄이 의존성 주입의 핵심 장면입니다.
    return SignUpService(
        user_repository=user_repository,
        email_sender=email_sender,
    )
