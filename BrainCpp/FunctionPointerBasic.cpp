#include <iostream>
using namespace std;

void Dog()
{
    cout << "I'm a dog\n";
}

void Cat()
{
    cout << "I'm a cat\n";
}

int main()
{
    // 함수 포인터 정의
    void (*p)();

    // Dog() 함수를 가리키게 한 후에 호출
    p = &Dog;
    (*p)(); // 호출

    // Cat() 함수를 가리키게 한 후에 호출
    p = &Cat;
    (*p)(); // 호출

    return 0;
}


