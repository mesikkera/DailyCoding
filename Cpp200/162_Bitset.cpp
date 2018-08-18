#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main()
{
    // bitset 선언 및 초기화(정수, 16진수, 문자열)
    // bitset 초기화: 정수
    bitset<8> data1(100);
    // bitset 초기화: 16진수
    bitset<8> data2(0x78);
    // bitset 초기화: 문자열
    bitset<8> data3(string("11110000"));

    cout << "data1 : " << data1 << endl;
    cout << "data2 : " << data2 << endl;
    cout << "data3 : " << data3 << endl;

    // 모든 bit를 1로 설정
    data1.set();

    cout << endl << "== data1 ==" << endl;
    // all(): 모든 비트가 1이면 true를 리턴
    cout << "data1 all: " << data1.all() << endl;
    // any(): 하나의 비트만 1이어도 true 리턴
    cout << "data1 any: " << data1.any() << endl;
    // none(): 모든 비트가 0이어야 true를 리턴
    cout << "data1 none: " << data1.none() << endl;

    // reset(): 모든 비트를 0으로 설정
    data2.reset();

    cout << endl << "== data2 ==" << endl;
    cout << "data2 all: " << data2.all() << endl;
    cout << "data2 any: " << data2.any() << endl;
    cout << "data2 none: " << data2.none() << endl;

    return 0;
}