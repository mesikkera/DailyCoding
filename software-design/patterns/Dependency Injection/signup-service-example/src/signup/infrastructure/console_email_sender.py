class ConsoleEmailSender:
    # EmailSender Protocol을 만족하는 실행용 구현체입니다.
    # 실제 이메일 API를 호출하는 대신 콘솔에 메시지를 출력해서,
    # 예제의 관심사가 외부 서비스 연동이 아니라 DI 구조에 머물도록 합니다.
    def send_welcome(self, email: str) -> None:
        # SignUpService는 이 메서드가 콘솔 출력인지, SMTP 전송인지, 외부 API 호출인지 모릅니다.
        # 이처럼 세부 구현을 infrastructure 계층에 숨기는 것이 분리의 핵심입니다.
        print(f"{email}님, 가입을 환영합니다.")
