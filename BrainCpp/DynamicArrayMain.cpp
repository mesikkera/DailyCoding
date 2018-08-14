#include "DynamicArray.h"
#include <iostream>
using namespace std;

void UseArray(DynamicArray& arr);

int main()
{
    // 크기가 10인 배열 객체
    DynamicArray arr(10);

    // // 각 원소에 10, 20, 30, ... 100의 순서로 값을 넣는다.
    // for (int i = 0; i < 10; ++i)
    //     arr.SetAt(i, (i+1)*10);

    // // 배열의 크기 출력 및 각 원소의 값을 역순으로 출력
    // cout << "Size of arr = " << arr.GetSize() << endl;

    // for (int i = 9; i >= 0; --i)
    //     cout << "arr[" << i << "] = " << arr.GetAt(i) << endl;

    // 반환값을 사용한 예외 처리
    // 올바른 인덱스를 참조시
    // bool b;
    // b = arr.SetAt(5, 0);

    // if(!b) 
    //     cout << "arr[5] Fail!\n";
    
    // // 예외 사항: 범위 밖의 인덱스 참조
    // b = arr.SetAt(20, 0);
    // if (!b) 
    //     cout << "arr[20] 사용 실패!\n";
    
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