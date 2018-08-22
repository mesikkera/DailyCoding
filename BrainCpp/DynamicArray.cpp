#include "DynamicArray.h"
#include "MyException.h"

DynamicArray::DynamicArray(int arraySize)
{
    // 동적으로 메모리를 할당
    arr = new int [arraySize];

    // 배열의 길이 보관
    size = arraySize;
}

DynamicArray::~DynamicArray()
{
    // 메모리 해제
    delete[] arr;
    arr = 0;
}

// 원소의 값을 바꾼다.
// 인덱스의 범위가 잘못된 경우 false 반환
// 1) 반환 값을 사용한 예외 처리를 사용하게 되면 함수를 호출할 때마다 매번 반환 값을 비교해야 하는 번거로움.
void DynamicArray::SetAt(int index, int value)
{
    // 인덱스 확인: 매개 변수 index의 범위를 검사한 뒤에 문제가 있다면 false 반환
    if (index < 0 || index >= GetSize())
        throw MyException(this, "Out of Range!!!", index);

    arr[index] = value;
}

// 원소의 값을 반환
int DynamicArray::GetAt(int index) const
{
    // 인덱스 범위가 맞지 않으면 예외를 던진다.
    if (index < 0 || index >= GetSize())
        throw MyException(this, "Out of Range!!!", index);

    return arr[index];
}

// 배열의 길이를 반환
int DynamicArray::GetSize() const 
{
    return size;
}