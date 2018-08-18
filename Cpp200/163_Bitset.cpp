#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main()
{
    bitset<8> data1(1);
    bitset<8> data2(0x01);

    cout << "data1 : " << data1 << endl;
    cout << "data2 : " << data2 << endl;

    // set()를 이용하여 하나의 비트만 수정 가능
    // set(index, value)
    // index: 수정할 비트의 인덱스
    // value: 설정할 값
    data1.set(0, false);
    data1.set(2, 1);

    cout << endl << "== data1 ==" << endl;
    cout << "data1 : " << data1 << endl;
    
    // [index] 를 이용하여 하나의 비트 수정 가능
    data2[4] = false;
    // flip(index): 해당 index의 값을 반전
    data2.flip(5);

    cout << endl << "== data2 ==" << endl;
    cout << "data2 : " << data2 << endl;

    string data1_str = data1.to_string();
    int data2_int = data2.to_ulong();

    cout << endl << "== 변환 ==" << endl;
    cout << "data1 : " << data1_str << endl;
    cout << "data2 : " << data2_int << endl;

    return 0;
}