#include "ComplexClass.h"

int main()
{
    Complex c1(1, 1);
    Complex c2(2, 2);
    Complex c3(0, 0);

    // + 연산자를 사용한 덧셈
    c3 = c1 + c2;
    c3 = c1.operator+(c2);

    return 0;
}