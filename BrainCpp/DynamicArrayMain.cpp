#include "DynamicArray.h"
#include <iostream>
using namespace std;

void UseArray(DynamicArray& arr);

int main()
{
    // 크기가 10인 배열 객체
    DynamicArray arr(10);

    // 각 원소에 10, 20, 30, ... 100의 순서로 값을 넣는다.
    for (int i = 0; i < 10; ++i)
        arr.SetAt(i, (i+1)*10);

    // 배열의 크기 출력 및 각 원소의 값을 역순으로 출력
    cout << "Size of arr = " << arr.GetSize() << endl;

    for (int i = 9; i >= 0; --i)
        cout << "arr[" << i << "] = " << arr.GetAt(i) << endl;

    return 0;
}
