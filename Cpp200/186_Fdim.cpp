#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // fdim(): 두 숫자를 인자로 받아 차이를 반환.
    // 첫번째 인자가 더 크면 차이를 반환, 두 번째 인자가 더 크면 0을 반환
    cout << fdim(-1.0, 0.0) << endl;
    cout << fdim(1.0, 0.0) << endl;
    cout << fdim(0.0, 0.0) << endl;
    cout << fdim(5, 1) << endl;
    cout << fdim(6, 15) << endl;
    cout << fdim(4.9, 1.1) << endl;
    cout << fdim(5.9, 20.1) << endl;

    return 0;
}