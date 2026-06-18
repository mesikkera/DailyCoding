class InMemoryUserRepository:
    # UserRepository Protocol을 만족하는 실행용 저장소 구현체입니다.
    # 데이터를 프로세스 메모리의 set에만 저장하므로 프로그램이 종료되면 데이터는 사라집니다.
    # 대신 설치나 설정 없이 DI 예제의 저장소 역할을 보여주기에는 충분합니다.
    def __init__(self) -> None:
        # set을 사용하면 이메일 존재 여부를 빠르게 확인할 수 있습니다.
        # 이 예제에서는 이메일 자체가 회원을 식별하는 값으로 쓰입니다.
        self.emails: set[str] = set()

    def exists(self, email: str) -> bool:
        # 서비스가 중복 가입 여부를 확인할 때 호출합니다.
        # 저장소 내부 자료구조가 set이라는 사실은 이 클래스 안에만 갇혀 있습니다.
        return email in self.emails

    def save(self, email: str) -> None:
        # 회원가입이 성공한 이메일을 저장합니다.
        # 같은 이메일을 다시 add해도 set 특성상 중복 저장되지는 않지만,
        # 중복 가입 검증 책임은 SignUpService가 담당합니다.
        self.emails.add(email)
