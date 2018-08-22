#include "DynamicArray.h"
#include "MyException.h"
#include <iostream>
using namespace std;

void UseArray(DynamicArray& arr1, DynamicArray& arr2);

int main()
{
    // 배열 객체를 2개 생성
    DynamicArray arr1(10);
    DynamicArray arr2(8);

    UseArray(arr1, arr2);

    return 0;
}

void UseArray(DynamicArray& arr1, DynamicArray& arr2)
{
    try
    {
        arr1.SetAt(5, 100);
        arr2.SetAt(5, 100);

        arr1.SetAt(8, 100);
        arr2.SetAt(8, 100);

        arr1.SetAt(10, 100);
        arr2.SetAt(10, 100);
    }
    catch(MyException& ex)
    {
        // 두 배열의 주소를 먼저 출력
        cout << "&arr1 = " << &arr1 << "\narr2 = " << &arr2 << endl;
        
        // 예외에 대한 자세한 정보 출력
        cout << "예외를 던진 객체의 주소 = " << ex.sender << endl;
        cout << "예외에 대한 설명 = " << ex.description << endl;
        cout << "부가 정보 = " << ex.info << endl;
    }
}
