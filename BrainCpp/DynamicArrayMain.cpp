#include "DynamicArray.h"
#include "MyException.h"
#include <iostream>
using namespace std;

void UseMemory();
void UseArray(DynamicArray& arr1, DynamicArray& arr2);

int main()
{
    // 배열 객체를 2개 생성
    DynamicArray arr1(10);
    DynamicArray arr2(8);

    UseArray(arr1, arr2);

    return 0;
}

void UseMemory()
{
    // 1000 바이트를 할당하려다 실패했다고 가정
    throw MemoryException(NULL, 1000);
}

void UseArray(DynamicArray& arr1, DynamicArray& arr2)
{
    try
    {
        arr1.SetAt(5, 100);
        arr2.SetAt(5, 100);

        UseMemory();

        arr1.SetAt(8, 100);
        arr2.SetAt(8, 100);

        arr1.SetAt(10, 100);
        arr2.SetAt(10, 100);
    }
    catch(MyException& ex)
    {
        // OutOfRangeException과 MemoryException 모두
        // 여기서 잡을 수 있다.
        cout << "예외에 대한 설명 = " << ex.description << endl;
    }
}
