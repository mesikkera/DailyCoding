#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main()
{
    tuple<int> data1(1);
    tuple<int, double> data2(1, 2.3);
    tuple<int, double, char> data3(1, 2.3, 'a');

    // 튜플 크기 계산 방법
    // 가장 큰 자료형 * 인자 개수 = 튜플 크기
    cout << sizeof(data1) << ", " << sizeof(data2) << ", " << sizeof(data3) << endl;

    return 0;
}