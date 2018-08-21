#include "DynamicArray.h"
#include <iostream>
using namespace std;

void UseArray(DynamicArray& arr);

int main()
{
    // 크기가 10인 배열 객체
    DynamicArray arr(10);

    UseArray(arr);

    return 0;
}

void UseArray(DynamicArray& arr)
{
    try
    {
        arr.SetAt(5, 100);
        arr.SetAt(8, 100);
        arr.SetAt(10, 100);
    }
    catch(const char* ex)
    {
        cout << "예외 종류 : " << ex << endl;
    }
}
