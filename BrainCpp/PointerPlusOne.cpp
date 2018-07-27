#include <iostream>
using namespace std;

int main()
{
    // 배열 정의
    int array[10];

    // 포인터가 array[5]를 가리키게.
    int* p = &array[5];

    cout << "p = " << p << endl;
    cout << "&array[5] = " << &array[5] << endl;
    cout << endl;
    
    p++;

    cout << "p = " << p << endl;
    cout << "&array[6] = " << &array[6] << endl;

    return 0;
}