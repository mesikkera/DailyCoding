#include <iostream>
using namespace std;

// 공용체 정의
union MyUnion
{
    int i;
    void* p;
};

int main()
{
    // 공용체 변수 정의
    MyUnion uni;

    // uni.i, uni.p의 주소 확인
    cout << "&uni.i = " << &uni.i << endl;
    cout << "&uni.p = " << &uni.p << endl;
    cout << endl;
    
    // uni.i에 값 대입 및 결과 출력
    uni.i = 0x12345678;
    cout << hex;
    cout << "uni.i = " << uni.i << endl;
    cout << "uni.p = " << uni.p << endl;
    cout << endl;

    // uni.p에 값 대입 및 결과 출력
    uni.p = (void*)0x87654321;
    cout << "uni.i = " << uni.i << endl;
    cout << "uni.p = " << uni.p << endl;

    return 0;
}