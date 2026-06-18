from pathlib import Path
import sys

# 이 예제는 패키지 설치 과정을 생략하고 바로 실행해볼 수 있도록 만들었습니다.
# 일반적인 프로젝트라면 패키지를 설치하거나 실행 환경을 더 정교하게 구성하지만,
# 여기서는 학습자가 `python main.py`만으로 DI 흐름을 확인하는 것이 더 중요합니다.
sys.path.insert(0, str(Path(__file__).parent / "src"))

from signup.container import create_signup_service


def main() -> None:
    # 실행 코드의 책임은 "객체를 조립한 뒤 유스케이스를 호출하는 것"입니다.
    # 회원가입 규칙 자체는 SignUpService 안에 있고,
    # main.py는 어떤 저장소와 이메일 전송기를 쓸지 결정된 서비스를 받아 사용합니다.
    email = "dev@example.com"
    service = create_signup_service()
    user = service.sign_up(email)

    # 환영 이메일 출력은 ConsoleEmailSender가 담당하고,
    # 이 메시지는 main.py가 유스케이스 호출 결과를 보여주기 위해 출력합니다.
    print(f"{user.email} 사용자가 가입되었습니다.")


if __name__ == "__main__":
    # Python 파일을 직접 실행했을 때만 예제 프로그램을 시작합니다.
    # 테스트에서 이 파일을 import하더라도 main()이 자동 실행되지 않게 하는 관용적인 구조입니다.
    main()
