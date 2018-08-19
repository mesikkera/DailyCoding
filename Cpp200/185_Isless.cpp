#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x = 10;
    int y = 20;
    double a = 12.2;
    double b = 5.6;

    cout << boolalpha;
    // isless(): 두 인수 중 앞의 값이 더 크면 false, 두 번째 값이 더 크면 true 리턴
    cout << isless(20, 11) << endl;
    cout << isless(x, y) << endl;
    cout << isless(a, b) << endl;
    cout << isless(x, b) << endl;

    return 0;
}