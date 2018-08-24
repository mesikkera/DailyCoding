#include "ComplexClass.h"

int main()
{
    Complex c1(1, 1);
    Complex c2(2, 2);
    Complex c3(0, 0);
    Complex prefix(0, 0);
    Complex postfix(0, 0);

    // + 연산자를 사용한 덧셈
    c3 = c1 + c2;
    c3 = c1.operator+(c2);

    // 전치 연산
    prefix = ++c1;

    // 후치 연산
    postfix = c1++;

    return 0;
}