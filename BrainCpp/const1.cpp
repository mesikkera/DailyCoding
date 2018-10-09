#include <iostream>
using namespace std;

int getSize()
{
    return 200;
}

int main()
{
    const int size = 100;
    const int bufferSize = getSize();

    // const 로 선언된 변수의 값을 변경하면 컴파일 오류 발생
    // const로 선언된 변수는 반드시 초기화를 해야 한다.
    // size = 200;
    // const int count;
    return 0;
}