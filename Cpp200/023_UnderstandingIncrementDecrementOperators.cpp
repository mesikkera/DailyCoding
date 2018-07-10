#include <iostream>

using namespace std;

int main()
{
    int x = 1;

    // x++: x를 사용한 뒤 1 증가
    // ++x: x를 1증가한 뒤 사용
    // x--: x를 사용한 뒤 1 감소
    // --x: x를 1감소한 뒤 사용
    cout << "x = " << x++ << endl;
    cout << "x = " << x++ << endl;
    cout << "x = " << ++x << endl;
    cout << "x = " << x-- << endl;
    cout << "x = " << x-- << endl;
    cout << "x = " << --x << endl;

    return 0;
}