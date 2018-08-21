#include "DynamicArray.h"
#include <iostream>
using namespace std;

void UseArray(DynamicArray& arr);

int main()
{
    // 크기가 10인 배열 객체
    DynamicArray arr(10);

    // 올바른 인덱스 참조
    bool b;
    b = arr.SetAt(5, 0);
    if (!b)
        cout << "arr[5] 사용 실패!!" << endl;

    // 범위 밖의 인덱스 참조
    b = arr.SetAt(20, 0);
    if (!b)
        cout << "arr[20] 사용 실패!!" << endl;
    return 0;
}
