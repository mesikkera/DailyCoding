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
    // �Լ��� �����ϴ� ��: ����(argument).
    // �Լ� ���ο����� ���ڸ� �����Ͽ� ���.
    Minus(5, 3);

    cout << "x + y = " << Plus(2, 6) << endl;

    return 0;
}