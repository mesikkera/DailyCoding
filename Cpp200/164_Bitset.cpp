#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    bitset<4> data1(6);     // 0110
    bitset<4> data2(0x09);  // 1001

    // OR 연산: 한 비트만 1이어도 결과가 1
    auto result = data1 | data2;
    cout << "data1 | data2 = " << result << endl;

    // AND 연산: 두 비트가 모두 1일 경우만 1
    result = data1 & data2;
    cout << "data1 & data2 = " << result << endl;

    // XOR 연산: 두 비트가 각각 0, 1일 경우만 1
    result = data1 ^ data2;
    cout << "data1 ^ data2 = " << result << endl;

    // 전체 비트를 왼쪽으로 1만큼 이동
    result = data1 << 1;
    cout << "data1 << 1 = " << result << endl;

    // 전체 비트를 오른쪽으로 1만큼 이동
    result = data1 >> 1;
    cout << "data1 >> 1 = " << result << endl;

    // 비트 전체 반전
    result = ~data1;
    cout << "~data1 = " << result << endl;

    return 0;
}