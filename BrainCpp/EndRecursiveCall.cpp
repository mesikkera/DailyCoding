#include <iostream>
using namespace std;

void WhilePositive(int n)
{
    // 인자 출력
    cout << "n = " << n << endl;

    // 인자가 0보다 작다면 재귀호출 종료
    if (n < 0)
        return ;

    // 인자가 0보다 크면 재귀호출
    WhilePositive(n - 1);

    // 인자 출력
    cout << "n = " << n << endl;
}

int main()
{
    WhilePositive(10);

    return 0;
}