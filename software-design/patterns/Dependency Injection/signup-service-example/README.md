# Dependency Injection Example: Sign Up Service

이 예제는 의존성 주입(Dependency Injection)을 작은 회원가입 서비스로 이해하기 위한 소규모 Python 프로젝트입니다.

문서에서 배운 의존성 주입 개념을 코드로 확인하는 것이 목적입니다. 특히 서비스 객체가 저장소, 알림 전송기 같은 구체 구현을 직접 생성하지 않고, 외부에서 전달받도록 구성하는 데 중점을 둡니다.

이 프로젝트는 테스트를 먼저 작성한 뒤 구현을 따라가는 방식으로 진행합니다. Python 테스트는 `pytest`를 기준으로 작성합니다.

## 예제 시나리오

회원가입 기능을 구현합니다.

요구사항은 단순합니다.

- 사용자는 이메일로 가입할 수 있다.
- 이미 가입된 이메일이면 가입에 실패한다.
- 가입에 성공하면 사용자 저장소에 이메일을 저장한다.
- 가입에 성공하면 환영 이메일을 전송한다.
- 테스트에서는 실제 이메일 전송 대신 가짜 객체를 사용한다.

이 예제의 핵심은 회원가입 기능 자체가 아니라, `SignUpService`가 구체적인 저장 방식이나 알림 전송 방식을 모른다는 점입니다.

## 중점 학습 내용

이 프로젝트에서는 다음 내용을 중점적으로 확인합니다.

- 생성자 주입을 이용한 의존성 주입
- 서비스 코드와 구체 구현의 분리
- `Protocol`을 이용한 역할 중심 추상화
- 테스트에서 Fake 객체를 주입하는 방식
- 객체 생성과 연결을 한곳에서 관리하는 간단한 조립 코드
- 의존성 주입이 테스트 가능성과 변경 용이성을 어떻게 높이는지
- 테스트를 먼저 작성하고 구현을 맞춰가는 흐름

## 프로젝트 구조

예상 구조는 다음과 같습니다.

```text
signup-service-example/
  README.md
  main.py
  src/
    signup/
      application/
        ports.py
        signup_service.py
      domain/
        user.py
      infrastructure/
        console_email_sender.py
        in_memory_user_repository.py
      container.py
  tests/
    test_signup_service.py
```

각 디렉토리의 역할은 다음과 같습니다.

- `domain/`: 도메인 모델을 둡니다.
- `application/`: 핵심 유스케이스와 추상화된 포트를 둡니다.
- `infrastructure/`: 메모리 저장소, 콘솔 이메일 전송기 같은 구체 구현을 둡니다.
- `container.py`: 실제 객체를 생성하고 연결하는 조립 코드를 둡니다.
- `tests/`: 의존성 주입을 활용한 `pytest` 테스트 코드를 둡니다.

## 설계 방향

`SignUpService`는 다음 두 의존성에 기대어 동작합니다.

- `UserRepository`
- `EmailSender`

하지만 `SignUpService`는 이들이 어떤 클래스로 구현되어 있는지 알지 못합니다.

예를 들어 실행 코드에서는 다음 구현체를 사용할 수 있습니다.

- `InMemoryUserRepository`
- `ConsoleEmailSender`

테스트 코드에서는 다음과 같은 가짜 객체를 사용할 수 있습니다.

- `FakeUserRepository`
- `FakeEmailSender`

이 구조 덕분에 서비스 코드는 변경하지 않고도 저장 방식이나 이메일 전송 방식을 교체할 수 있습니다.

## 테스트 우선 개발 흐름

구현은 다음 순서로 진행합니다.

1. 회원가입 성공 테스트를 먼저 작성한다.
2. 중복 이메일 가입 실패 테스트를 작성한다.
3. 테스트를 통과할 만큼만 `SignUpService`를 구현한다.
4. `Protocol`로 저장소와 이메일 전송기의 역할을 분리한다.
5. 실행용 구현체와 테스트용 Fake 객체를 나눈다.
6. `main.py`에서 실제 객체를 조립해 실행한다.

이 흐름을 통해 의존성 주입이 테스트를 쉽게 만드는 이유를 코드로 확인합니다.

## 실행 방법

이 예제의 애플리케이션 코드는 Python 표준 라이브러리만 사용합니다. 테스트 실행에는 `pytest`가 필요하며, Python 의존성은 `uv`를 기준으로 관리합니다.

프로젝트 디렉토리로 이동합니다.

```bash
cd "software-design/patterns/Dependency Injection/signup-service-example"
```

예제 프로그램을 실행합니다.

```bash
uv run python main.py
```

테스트를 실행합니다.

```bash
uv run pytest
```

처음 실행한다면 먼저 의존성을 동기화합니다.

```bash
uv sync
```

## 기대 실행 결과

`main.py`를 실행하면 회원가입이 수행되고, 콘솔에 환영 이메일 전송 메시지가 출력됩니다.

예상 출력 예시는 다음과 같습니다.

```text
dev@example.com님, 가입을 환영합니다.
dev@example.com 사용자가 가입되었습니다.
```

테스트에서는 실제 콘솔 이메일 전송기를 사용하지 않고, 가짜 이메일 전송기를 주입하여 환영 이메일 전송 요청이 발생했는지만 검증합니다.

## 이 예제에서 확인할 질문

코드를 읽으면서 다음 질문을 확인해보면 좋습니다.

- `SignUpService`는 저장소 구현체를 직접 생성하는가?
- `SignUpService`는 이메일 전송 구현체를 직접 생성하는가?
- 테스트에서는 실제 구현 대신 무엇을 주입하는가?
- 저장소 구현을 바꾸면 서비스 코드를 수정해야 하는가?
- 객체 생성과 연결 책임은 어디에 모여 있는가?

## 확장 아이디어

기본 예제를 이해한 뒤에는 다음 방향으로 확장할 수 있습니다.

- `JsonFileUserRepository`를 추가해 저장 방식을 파일 기반으로 변경하기
- `ConsoleEmailSender` 대신 `FakeEmailSender`를 테스트에서 사용하기
- 이메일 형식 검증 로직 추가하기
- 간단한 DI 컨테이너 클래스를 직접 만들어보기
- Clean Architecture 구조로 디렉토리와 의존성 방향 정리하기
