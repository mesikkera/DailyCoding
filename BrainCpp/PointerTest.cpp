#include <iostream>
using namespace std;

int main()
{
    // int 타입의 변수 정의
    int i = 0x12345678;

    // char* 타입의 포인터로 i를 가리킨다.
    char* pc = (char*)&i;

    // pc가 가리키는 값을 구한다.
    cout << hex;
    cout << "*pc = " << (int)*pc << endl;

    // 초기화 하지 않고 사용
    int* p;
    cout << p << endl;
    *p = 128;
    cout << p << endl;
    cout << *p << endl;

    // 포인터 변수는 항상 0으로 초기화한다.
    // 포인터 변수를 사용하기 전에는 0이 아닌지 비교한다.

    int* pt = NULL;
    
    if(pt != 0)
        *pt = 30;

    char c = 'B';
    cout << "C의 주소 : " << (int*)&c << endl;
    cout << "C의 주소 : " << &c << endl;
    cout << "C : " << *p << endl;
    cout << "C : " << (char*)p << endl;

    return 0;
}