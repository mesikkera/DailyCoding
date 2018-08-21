#include "DynamicArray.h"

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
bool DynamicArray::SetAt(int index, int value)
{
    // 인덱스 확인: 매개 변수 index의 범위를 검사한 뒤에 문제가 있다면 false 반환
    if (index < 0 || index >= GetSize())
        return false;

    arr[index] = value;

    return true;
}

// 원소의 값을 반환
int DynamicArray::GetAt(int index) const
{
    return arr[index];
}

// 배열의 길이를 반환
int DynamicArray::GetSize() const 
{
    return size;
}