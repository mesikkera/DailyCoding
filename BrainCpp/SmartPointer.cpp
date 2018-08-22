#include <iostream>
using namespace std;

// 스마트 포인터 클래스
class SmartPointer
{
public:
    SmartPointer(char* p) : ptr(p)
    {
        // 생성자에서는 char* 타입의 인자를 받아서
        // 멤버변수 ptr에 보관
    }
    ~SmartPointer()
    {
        // 소멸자에서는 멤버 변수 ptr에 보관도니 값을 사용해서 
        // 메모리를 해제한다. 소멸자가 반드시 호출된다는 점을 확인.

        // 소멸자 호출 확인
        cout << "메모리 해제" << endl;

        delete[] ptr;
    }

public:
    char* const ptr;
};

void A();
void B();

int main()
{
    try
    {
        A();
    }
    catch (const char* ex)
    {
        cout << "예외 잡음 : " << ex << endl;
    }

    return 0;
}

void A()
{
    // 메모리 할당
    char* p = new char [100];

    // 메모리를 스마트 포인터에 보관
    SmartPointer sp(p);

    cout << "예외 발생 전" << endl;

    // 예외를 던지는 함수 호출
    B();

    cout << "예외 발생 후" << endl;

    // 메모리를 따로 해제해줄 필요 없다.
    // 함수가 정상적으로 종료된 경우나 예외에 의해서 종료된 경우
    // 모두 스마트 포인터 객체 SP의 소멸자가 반드시 호출된다.
    // SP의 소멸자에서 메모리를 해제해주기 때문에 
    // 따로 신경 쓸 부분은 없다.
    
    // delete[] p;
    // p = NULL;

}

void B()
{
    throw "Exception!!";
}