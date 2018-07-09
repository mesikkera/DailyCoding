#include <iostream>

using namespace std;

int main()
{
    // 부호 연산자 +, -는 양수를 음수로, 음수를 양수로 변환하는 역할을 담당.
    int x = 1;
    int y = -1;
    int z = -2;

    cout << "1 + (-1) = " << x + y << endl;
    cout << "-1 + -2 = " << y + z << endl;

    return 0;
}