# 디자인 패턴과 의존성 주입

## 1. 디자인 패턴이란?

디자인 패턴은 소프트웨어를 설계할 때 자주 마주치는 문제에 대해, 이미 많은 개발자들이 검증해 온 해결 방식입니다.

여기서 중요한 점은 디자인 패턴이 완성된 코드 조각이 아니라는 것입니다. 디자인 패턴은 특정 언어의 문법이나 라이브러리보다 더 높은 수준의 설계 아이디어에 가깝습니다. 같은 패턴이라도 Python, Java, Kotlin, TypeScript에서 구현 형태는 달라질 수 있습니다.

예를 들어 다음과 같은 상황을 생각해볼 수 있습니다.

- 객체를 매번 새로 만들지 않고 하나만 공유하고 싶다.
- 기능은 비슷하지만 생성 방식이 다른 객체들을 일관되게 만들고 싶다.
- 어떤 객체의 내부 구현을 바꾸더라도 사용하는 쪽 코드를 덜 흔들리게 만들고 싶다.
- 커다란 클래스를 작은 역할들로 나누고 싶다.
- 테스트하기 쉬운 구조로 코드를 만들고 싶다.

이런 문제들은 프로젝트마다 반복해서 등장합니다. 디자인 패턴은 이런 반복되는 문제에 이름을 붙이고, 해결 방향을 공유할 수 있게 해줍니다.

## 2. 디자인 패턴이 필요한 이유

디자인 패턴을 배우는 이유는 단순히 패턴 이름을 외우기 위해서가 아닙니다. 핵심은 코드의 변경 가능성을 다루는 힘을 기르는 것입니다.

처음에는 아래와 같은 코드도 충분히 괜찮아 보입니다.

```python
class EmailSender:
    def send(self, message: str) -> None:
        print(f"이메일 전송: {message}")


class OrderService:
    def place_order(self, order_id: str) -> None:
        sender = EmailSender()
        sender.send(f"주문이 완료되었습니다. 주문 번호: {order_id}")


service = OrderService()
service.place_order("A001")
```

작은 프로그램에서는 문제가 잘 보이지 않습니다. 하지만 요구사항이 바뀌면 불편함이 드러납니다.

- 이메일 대신 문자 메시지를 보내야 한다면?
- 운영 환경에서는 실제 이메일을 보내고, 테스트 환경에서는 가짜 전송 객체를 쓰고 싶다면?
- 주문 서비스가 알림 방식의 구체적인 구현을 몰라도 되게 만들고 싶다면?

디자인 패턴은 이런 변경 지점들을 더 유연하게 다루도록 도와줍니다.

## 3. 디자인 패턴의 대표적인 분류

전통적으로 디자인 패턴은 크게 세 가지로 나누어 설명합니다.

### 3.1 생성 패턴

객체를 어떻게 만들 것인지에 관심이 있는 패턴입니다.

대표적인 예시는 다음과 같습니다.

- Singleton
- Factory Method
- Abstract Factory
- Builder
- Prototype

예를 들어 객체 생성 과정이 복잡하거나, 사용하는 쪽에서 구체 클래스를 직접 알 필요가 없게 만들고 싶을 때 생성 패턴을 고려할 수 있습니다.

간단한 Factory 예시는 다음과 같습니다.

```python
class EmailNotifier:
    def send(self, message: str) -> None:
        print(f"이메일 알림: {message}")


class SmsNotifier:
    def send(self, message: str) -> None:
        print(f"문자 알림: {message}")


def create_notifier(channel: str):
    if channel == "email":
        return EmailNotifier()
    if channel == "sms":
        return SmsNotifier()
    raise ValueError(f"지원하지 않는 알림 채널입니다: {channel}")


notifier = create_notifier("email")
notifier.send("가입을 환영합니다.")
```

객체를 만드는 책임이 `create_notifier`에 모였기 때문에, 사용하는 쪽 코드는 생성 세부 사항을 덜 알게 됩니다.

### 3.2 구조 패턴

객체나 클래스를 어떻게 조합해서 더 큰 구조를 만들 것인지에 관심이 있는 패턴입니다.

대표적인 예시는 다음과 같습니다.

- Adapter
- Decorator
- Facade
- Proxy
- Composite

예를 들어 외부 라이브러리의 인터페이스가 우리 코드와 맞지 않을 때 Adapter 패턴을 사용할 수 있습니다.

```python
class ExternalPaymentClient:
    def request_payment(self, amount: int) -> str:
        return f"{amount}원 결제 요청 완료"


class PaymentAdapter:
    def __init__(self, client: ExternalPaymentClient) -> None:
        self.client = client

    def pay(self, price: int) -> str:
        return self.client.request_payment(price)


payment = PaymentAdapter(ExternalPaymentClient())
print(payment.pay(10_000))
```

`ExternalPaymentClient`의 메서드 이름은 `request_payment`이지만, 우리 서비스에서는 `pay`라는 더 단순한 인터페이스로 사용할 수 있습니다.

### 3.3 행위 패턴

객체들이 어떻게 책임을 나누고 협력할 것인지에 관심이 있는 패턴입니다.

대표적인 예시는 다음과 같습니다.

- Strategy
- Observer
- Command
- Template Method
- Chain of Responsibility

예를 들어 할인 정책이 여러 개라면 Strategy 패턴으로 계산 방식을 교체 가능하게 만들 수 있습니다.

```python
class FixedDiscount:
    def discount(self, price: int) -> int:
        return price - 1_000


class RateDiscount:
    def discount(self, price: int) -> int:
        return int(price * 0.9)


class PriceCalculator:
    def __init__(self, discount_policy) -> None:
        self.discount_policy = discount_policy

    def calculate(self, price: int) -> int:
        return self.discount_policy.discount(price)


calculator = PriceCalculator(RateDiscount())
print(calculator.calculate(20_000))
```

`PriceCalculator`는 고정 할인인지, 비율 할인인지 직접 판단하지 않습니다. 할인 정책 객체에게 계산을 맡깁니다.

## 4. 패턴을 배울 때 조심할 점

디자인 패턴은 강력하지만, 모든 코드에 억지로 적용해야 하는 규칙은 아닙니다.

패턴을 과하게 사용하면 오히려 코드가 복잡해질 수 있습니다. 클래스와 인터페이스는 많아졌는데 실제 문제는 단순한 경우도 많습니다. 좋은 설계는 패턴을 많이 쓰는 설계가 아니라, 변경에 잘 버티면서도 읽기 쉬운 설계입니다.

따라서 패턴을 사용할 때는 다음 질문을 먼저 해보는 것이 좋습니다.

- 지금 이 코드에서 실제로 자주 바뀔 부분은 어디인가?
- 이 패턴을 적용하면 변경 비용이 줄어드는가?
- 테스트하기 쉬워지는가?
- 사용하는 사람이 코드를 더 쉽게 이해할 수 있는가?
- 단순한 함수나 작은 클래스로도 충분하지 않은가?

디자인 패턴은 목적이 아니라 도구입니다.

## 5. 의존성이란?

의존성 주입을 이해하려면 먼저 의존성이 무엇인지 알아야 합니다.

어떤 코드가 다른 코드 없이는 동작할 수 없다면, 그 코드는 다른 코드에 의존한다고 말할 수 있습니다.

```python
class UserRepository:
    def save(self, username: str) -> None:
        print(f"사용자 저장: {username}")


class UserService:
    def register(self, username: str) -> None:
        repository = UserRepository()
        repository.save(username)
```

`UserService`는 `UserRepository`에 의존합니다. 왜냐하면 사용자를 등록하려면 저장소가 필요하기 때문입니다.

문제는 `UserService`가 `UserRepository`를 직접 생성하고 있다는 점입니다.

```python
repository = UserRepository()
```

이렇게 되면 `UserService`는 사용자 등록이라는 비즈니스 흐름뿐 아니라, 어떤 저장소 구현을 사용할지도 직접 결정합니다.

작은 코드에서는 괜찮지만, 애플리케이션이 커질수록 다음 문제가 생깁니다.

- 저장 방식을 바꾸기 어렵다.
- 테스트에서 가짜 저장소로 대체하기 어렵다.
- 클래스가 너무 많은 책임을 가진다.
- 구체 클래스에 강하게 묶인다.

## 6. 의존성 주입이란?

의존성 주입은 객체가 필요한 의존성을 스스로 만들지 않고, 외부에서 전달받도록 하는 방식입니다.

의존성 주입은 제어의 역전(Inversion of Control, IoC)을 구현하는 대표적인 방법 중 하나입니다. 제어의 역전은 객체가 필요한 의존 객체를 직접 생성하고 관리하던 제어권이 객체 바깥으로 이동하는 것을 의미합니다. 여기서 바깥은 DI 컨테이너일 수도 있고, 애플리케이션의 조립 코드일 수도 있고, 프레임워크나 팩토리일 수도 있습니다.

DI는 이 제어권을 외부로 넘기는 구체적인 방식입니다. 즉, 객체는 "무엇이 필요한지"만 드러내고, "무엇을 만들어서 넣을지"는 외부에서 결정합니다.

영어로는 Dependency Injection, 줄여서 DI라고 부릅니다.

정확히 말하면 의존성 주입은 GoF의 전통적인 23가지 디자인 패턴 중 하나라기보다는, 객체지향 설계에서 널리 쓰이는 설계 기법에 가깝습니다. 하지만 디자인 패턴을 공부할 때 함께 다루기 좋습니다. 객체 간의 결합을 낮추고, 변경에 유연한 구조를 만드는 데 직접적으로 연결되기 때문입니다.

앞의 코드를 의존성 주입 방식으로 바꾸면 다음과 같습니다.

```python
class UserRepository:
    def save(self, username: str) -> None:
        print(f"사용자 저장: {username}")


class UserService:
    def __init__(self, repository: UserRepository) -> None:
        self.repository = repository

    def register(self, username: str) -> None:
        self.repository.save(username)


repository = UserRepository()
service = UserService(repository)
service.register("kim")
```

차이는 작아 보입니다.

```python
service = UserService(repository)
```

하지만 이 구조에서는 `UserService`가 `UserRepository`를 직접 만들지 않습니다. 필요한 저장소를 외부에서 받습니다.

이제 `UserService`는 "사용자를 등록할 때 저장소에 저장한다"는 흐름에 집중하고, 어떤 저장소를 사용할지는 외부에서 결정할 수 있습니다.

## 7. 의존성 주입 전후 비교

### 7.1 의존성 주입을 사용하지 않은 코드

```python
class ConsoleLogger:
    def log(self, message: str) -> None:
        print(f"[LOG] {message}")


class PaymentService:
    def pay(self, amount: int) -> None:
        logger = ConsoleLogger()
        logger.log(f"{amount}원 결제를 시작합니다.")
        print("결제 처리 완료")
```

`PaymentService`는 결제 처리와 로그 객체 생성이라는 두 가지에 관여합니다.

만약 로그를 파일로 남기고 싶다면 `PaymentService` 내부 코드를 수정해야 합니다.

### 7.2 의존성 주입을 사용한 코드

```python
class ConsoleLogger:
    def log(self, message: str) -> None:
        print(f"[LOG] {message}")


class PaymentService:
    def __init__(self, logger: ConsoleLogger) -> None:
        self.logger = logger

    def pay(self, amount: int) -> None:
        self.logger.log(f"{amount}원 결제를 시작합니다.")
        print("결제 처리 완료")


logger = ConsoleLogger()
service = PaymentService(logger)
service.pay(30_000)
```

이제 `PaymentService`는 로거를 직접 생성하지 않습니다. 외부에서 받은 로거를 사용합니다.

이 구조는 테스트하기도 쉬워집니다.

```python
class FakeLogger:
    def __init__(self) -> None:
        self.messages: list[str] = []

    def log(self, message: str) -> None:
        self.messages.append(message)


fake_logger = FakeLogger()
service = PaymentService(fake_logger)

service.pay(30_000)

assert fake_logger.messages == ["30000원 결제를 시작합니다."]
```

실제 콘솔 출력이나 파일 저장 없이도 `PaymentService`가 로그를 남기려고 했는지 확인할 수 있습니다.

## 8. 추상화와 함께 사용하는 의존성 주입

앞의 예제에는 아직 아쉬운 점이 있습니다.

```python
class PaymentService:
    def __init__(self, logger: ConsoleLogger) -> None:
        self.logger = logger
```

타입 힌트가 `ConsoleLogger`라는 구체 클래스에 묶여 있습니다. Python에서는 덕 타이핑 덕분에 동작 자체는 문제가 없지만, 설계 의도를 더 분명하게 표현하려면 추상화에 의존하도록 만들 수 있습니다.

Python에서는 `Protocol`을 사용해 "이런 메서드를 가진 객체라면 로거로 사용할 수 있다"는 계약을 표현할 수 있습니다.

```python
from typing import Protocol


class Logger(Protocol):
    def log(self, message: str) -> None:
        ...


class ConsoleLogger:
    def log(self, message: str) -> None:
        print(f"[LOG] {message}")


class FileLogger:
    def __init__(self, path: str) -> None:
        self.path = path

    def log(self, message: str) -> None:
        with open(self.path, "a", encoding="utf-8") as file:
            file.write(f"{message}\n")


class PaymentService:
    def __init__(self, logger: Logger) -> None:
        self.logger = logger

    def pay(self, amount: int) -> None:
        self.logger.log(f"{amount}원 결제를 시작합니다.")
        print("결제 처리 완료")


console_logger = ConsoleLogger()
payment_service = PaymentService(console_logger)
payment_service.pay(30_000)
```

이제 `PaymentService`는 `ConsoleLogger`가 아니라 `Logger`라는 추상적인 역할에 의존합니다.

이것은 객체지향 설계에서 자주 말하는 의존성 역전 원칙과도 연결됩니다.

> 고수준 정책은 저수준 구현에 의존하지 않아야 한다. 둘 다 추상화에 의존해야 한다.

쉽게 말하면 `PaymentService` 같은 중요한 비즈니스 흐름이 `ConsoleLogger`, `FileLogger` 같은 세부 구현에 끌려다니지 않게 만들자는 뜻입니다.

## 9. 의존성 주입의 방식

의존성 주입은 보통 세 가지 방식으로 설명합니다.

### 9.1 생성자 주입

객체를 만들 때 필요한 의존성을 생성자로 전달합니다.

```python
class OrderService:
    def __init__(self, repository, notifier) -> None:
        self.repository = repository
        self.notifier = notifier

    def place_order(self, order_id: str) -> None:
        self.repository.save(order_id)
        self.notifier.send(f"주문 완료: {order_id}")
```

가장 흔하고 추천되는 방식입니다. 객체가 동작하기 위해 반드시 필요한 의존성을 빠뜨리기 어렵고, 객체가 생성된 뒤에는 의존성이 비교적 안정적으로 유지됩니다.

### 9.2 메서드 매개변수 주입

특정 메서드를 호출할 때만 필요한 의존성을 인자로 전달합니다.

```python
class ReportService:
    def create_report(self, data: list[int], formatter) -> str:
        return formatter.format(data)
```

의존성이 객체 전체 생명주기 동안 필요한 것이 아니라, 특정 작업에서만 필요할 때 사용할 수 있습니다. 이 방식은 Strategy 패턴처럼 호출 시점마다 다른 구현을 유연하게 바꿔 사용하고 싶을 때도 유용합니다. 예를 들어 같은 `ReportService`라도 어떤 호출에서는 Markdown 포매터를, 다른 호출에서는 HTML 포매터를 전달할 수 있습니다.

다만 이것은 객체에 의존성을 나중에 설정하는 setter나 property 주입과는 다릅니다. 메서드 매개변수 주입은 의존성이 객체의 상태로 오래 남지 않고, 해당 호출 안에서만 사용된다는 점이 핵심입니다.

### 9.3 속성 주입

객체를 만든 뒤 속성으로 의존성을 넣어줍니다.

```python
class ConsoleNotifier:
    def send(self, message: str) -> None:
        print(f"알림: {message}")


class MessageService:
    notifier = None

    def send_message(self, message: str) -> None:
        if self.notifier is None:
            raise RuntimeError("notifier가 설정되지 않았습니다.")

        self.notifier.send(message)


service = MessageService()
service.notifier = ConsoleNotifier()
service.send_message("작업이 완료되었습니다.")
```

속성 주입은 유연하지만, 필요한 의존성이 설정되지 않은 상태로 객체가 사용될 위험이 있습니다. 그래서 꼭 필요한 의존성에는 생성자 주입이 더 안전한 경우가 많습니다.

이런 이유로 속성 주입은 주로 선택적인 의존성에 어울립니다. 해당 의존성이 없어도 객체의 핵심 기능은 동작하지만, 있으면 부가 기능이 활성화되는 경우입니다. 예를 들어 기본 로거는 생성자 주입으로 받고, 성능 분석을 위한 프로파일러는 필요할 때만 속성으로 설정할 수 있습니다.

순환 의존이 있는 객체들을 늦게 연결하기 위해 속성 주입을 사용하는 경우도 있습니다. 다만 순환 의존은 설계가 과하게 얽혔다는 신호일 수 있으므로, 속성 주입으로 우회하기 전에 책임 분리나 의존 방향을 다시 검토하는 편이 좋습니다.

## 10. 조금 더 현실적인 예제

회원가입 기능을 예로 들어보겠습니다.

요구사항은 다음과 같습니다.

- 사용자가 가입하면 저장소에 사용자 정보를 저장한다.
- 가입이 끝나면 환영 이메일을 보낸다.
- 테스트에서는 실제 이메일을 보내지 않아야 한다.

먼저 역할을 `Protocol`로 정의합니다.

```python
from typing import Protocol


class UserRepository(Protocol):
    def save(self, email: str) -> None:
        ...


class EmailSender(Protocol):
    def send_welcome(self, email: str) -> None:
        ...
```

구체 구현을 작성합니다.

```python
class InMemoryUserRepository:
    def __init__(self) -> None:
        self.users: list[str] = []

    def save(self, email: str) -> None:
        self.users.append(email)


class ConsoleEmailSender:
    def send_welcome(self, email: str) -> None:
        print(f"{email}님, 가입을 환영합니다.")
```

서비스는 추상화에 의존하도록 만듭니다.

```python
class SignUpService:
    def __init__(self, repository: UserRepository, email_sender: EmailSender) -> None:
        self.repository = repository
        self.email_sender = email_sender

    def sign_up(self, email: str) -> None:
        self.repository.save(email)
        self.email_sender.send_welcome(email)
```

실제 실행 코드는 필요한 의존성을 조립합니다.

```python
repository = InMemoryUserRepository()
email_sender = ConsoleEmailSender()

service = SignUpService(repository, email_sender)
service.sign_up("dev@example.com")
```

테스트에서는 가짜 이메일 전송기를 넣을 수 있습니다.

```python
class FakeEmailSender:
    def __init__(self) -> None:
        self.sent_emails: list[str] = []

    def send_welcome(self, email: str) -> None:
        self.sent_emails.append(email)


repository = InMemoryUserRepository()
fake_email_sender = FakeEmailSender()

service = SignUpService(repository, fake_email_sender)
service.sign_up("dev@example.com")

assert repository.users == ["dev@example.com"]
assert fake_email_sender.sent_emails == ["dev@example.com"]
```

이 예제에서 `SignUpService`는 실제 이메일을 보내는 방법을 모릅니다. 단지 `send_welcome`을 호출할 수 있는 객체를 받을 뿐입니다.

이 덕분에 서비스 코드는 더 테스트하기 쉬워지고, 이메일 전송 방식을 바꾸더라도 서비스 코드는 그대로 둘 수 있습니다.

## 11. 의존성 주입 컨테이너

작은 프로그램에서는 직접 객체를 만들어 전달하면 충분합니다.

```python
repository = InMemoryUserRepository()
email_sender = ConsoleEmailSender()
service = SignUpService(repository, email_sender)
```

하지만 애플리케이션이 커지면 객체 생성과 연결 코드가 많아집니다. 이때 의존성 주입 컨테이너를 사용할 수 있습니다.

의존성 주입 컨테이너는 객체를 어떻게 만들고 연결할지 관리해주는 도구입니다.

간단한 컨테이너를 직접 흉내 내보면 다음과 같습니다.

```python
class Container:
    def __init__(self) -> None:
        self.repository = InMemoryUserRepository()
        self.email_sender = ConsoleEmailSender()

    def sign_up_service(self) -> SignUpService:
        return SignUpService(
            repository=self.repository,
            email_sender=self.email_sender,
        )


container = Container()
service = container.sign_up_service()
service.sign_up("dev@example.com")
```

실제 프레임워크에서는 이 과정을 설정 파일, 데코레이터, 타입 힌트, 명시적인 provider 등록 등을 이용해 자동화합니다. Python에서도 `dependency-injector`, `punq` 같은 라이브러리들이 이런 아이디어를 구현합니다.

개발자는 각 클래스가 어떤 의존성을 필요로 하는지 선언하거나 컨테이너에 등록하고, 실제 객체 생성과 주입은 컨테이너에 맡길 수 있습니다. 이를 통해 애플리케이션의 객체 관계를 한곳에서 관리하고, 복잡한 의존성 연결을 일관되게 처리할 수 있습니다.
개발자는 각 클래스가 어떤 의존성을 필요로 하는지 선언하고, 어떤 구현체를 사용할지는 컨테이너 설정에서 한 번만 정의합니다. 그 후 애플리케이션의 여러 곳에서 `container.sign_up_service()`와 같이 필요한 객체를 요청하기만 하면, 컨테이너가 알아서 등록된 규칙에 따라 의존성 트리를 분석하고 객체를 생성하여 주입해 줍니다. 이를 통해 객체 생성과 사용의 관심사를 분리하고, 복잡한 의존성 관리를 자동화할 수 있습니다.

하지만 핵심 아이디어는 같습니다.

객체가 필요한 의존성을 직접 만들지 않고, 외부에서 조립해서 넣어준다.

## 12. 의존성 주입의 장점

의존성 주입을 사용하면 다음과 같은 장점이 있습니다.

- 테스트가 쉬워진다.
- 구현체를 교체하기 쉬워진다.
- 클래스의 책임이 줄어든다.
- 코드가 추상화에 의존하게 만들기 쉽다.
- 변경의 영향을 좁은 범위로 제한할 수 있다.

특히 테스트하기 쉬워진다는 점은 매우 큽니다.

외부 API, 데이터베이스, 파일 시스템, 이메일 서버처럼 느리거나 불안정한 요소를 직접 사용하면 테스트가 어려워집니다. 의존성 주입을 사용하면 이런 요소를 가짜 객체로 대체할 수 있습니다.

## 13. 의존성 주입의 단점

의존성 주입이 항상 좋은 것만은 아닙니다.

작은 코드에 과하게 적용하면 오히려 다음 문제가 생길 수 있습니다.

- 클래스와 파일이 불필요하게 많아진다.
- 실제 구현을 따라가기가 어려워진다.
- 객체를 어디서 만드는지 찾기 어려워진다.
- 단순한 로직도 복잡한 구조처럼 보일 수 있다.

예를 들어 아주 작은 스크립트에서는 아래처럼 단순하게 쓰는 편이 더 나을 수 있습니다.

```python
def greet(name: str) -> None:
    print(f"안녕하세요, {name}님")


greet("kim")
```

이런 코드에 굳이 `GreetingPrinter` 인터페이스와 구현체를 나눌 필요는 없습니다.

패턴은 복잡도를 줄이기 위해 쓰는 것이지, 복잡도를 만들기 위해 쓰는 것이 아닙니다.

## 14. 언제 의존성 주입을 고려할까?

다음 상황에서는 의존성 주입을 고려해볼 만합니다.

- 외부 시스템에 접근하는 코드가 있다.
- 테스트에서 실제 구현 대신 가짜 구현을 쓰고 싶다.
- 같은 역할에 여러 구현체가 있다.
- 비즈니스 로직이 구체적인 기술 구현에 묶이는 것이 부담스럽다.
- 객체 생성 로직이 점점 복잡해지고 있다.
- 클린 아키텍처나 헥사고날 아키텍처처럼 의존성 방향을 중요하게 다루는 구조를 만들고 있다.

반대로 다음 상황에서는 단순한 코드가 더 나을 수 있습니다.

- 한 번 쓰고 버릴 작은 스크립트다.
- 변경 가능성이 거의 없다.
- 추상화보다 직접적인 코드가 훨씬 읽기 쉽다.
- 테스트 대체 객체가 필요하지 않다.

## 15. 정리

디자인 패턴은 반복되는 설계 문제에 대한 검증된 해결 아이디어입니다. 그중 의존성 주입은 객체가 필요한 의존성을 직접 만들지 않고 외부에서 전달받도록 하는 방식입니다.

의존성 주입의 핵심은 다음과 같습니다.

- 객체는 자신이 사용할 구체 구현을 직접 생성하지 않는다.
- 필요한 의존성은 외부에서 전달받는다.
- 중요한 비즈니스 로직은 세부 구현보다 추상화에 의존하게 만든다.
- 테스트와 변경에 유리한 구조를 만든다.

한 문장으로 정리하면 다음과 같습니다.

> 의존성 주입은 "무엇을 사용할지"를 클래스 내부에서 결정하지 않고, 외부에서 결정해 넣어주는 설계 방식이다.

처음에는 단순히 `__init__`으로 객체를 전달하는 작은 변화처럼 보이지만, 이 작은 변화가 코드의 테스트 가능성, 확장성, 유지보수성에 큰 차이를 만듭니다.
