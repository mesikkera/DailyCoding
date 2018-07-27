#include <iostream>
using namespace std;

int main()
{
    // int 타입의 주소를 void 포인터에 보관
    int i = 400;
    void* pv = &i;

    int* pi = (int*)pv;
    cout << sizeof(void*) << endl;
    return 0;
}