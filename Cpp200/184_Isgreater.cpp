#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x = 10;
    int y = 20;
    double a = 12.2;
    double b = 5.6;

    // isgreater(): 두 인수 중 앞의 값이 크면 true, 두번 째 값이 크면 false 리턴
    cout << boolalpha;
    cout << isgreater(20, 10) << endl;
    cout << isgreater(x, y) << endl;
    cout << isgreater(a, b) << endl;
    cout << isgreater(x, b) << endl;

    return 0;
}