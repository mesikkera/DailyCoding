#include <iostream>
using namespace std;

int main()
{
    // 메모리 할당
    short* p = new short [100];

    // p에 보관한 주소 값 확인
    cout << "p = " << p << endl;

    // 메모리 해제
    // 메모리를 해제하고, NULL로 초기화 면서
    // 저장되어 있는 주소값을 초기화한다.
    delete [] p;
    p = NULL;

    // p에 보관한 주소 값 확인
    cout << "p = " << p << endl;

    // 메모리 해제
    delete [] p;
    p = NULL;

    return 0;
}