#include <iostream>
using namespace std;

int main()
{
    short* p = new short [100];

    cout << "p = " << p << endl;

    delete [] p;

    cout << "p = " << p << endl;

    delete [] p;

    // 메모리를 해제한다고 해서 메모리의 주소를 보관하고 있던
    // 포인터 변수까지 정리하는 것은 아니다.
    // 이 포인터 변수를 다시 NULL 값으로 초기화해주는 것이 개발자의 몫
    return 0;
}