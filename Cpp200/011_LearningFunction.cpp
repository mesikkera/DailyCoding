#include <iostream>

using namespace std;

void Minus(const int x, const int y)
{
    cout << "x - y = " << x - y << endl;
}

int Plus(const int x, const int y)
{
    return x + y;
}

int main()
{
    // 함수에 전달하는 값: 인자(argument).
    // 함수 내부에서는 인자를 복사하여 사용.
    Minus(5, 3);

    cout << "x + y = " << Plus(2, 6) << endl;

    return 0;
}