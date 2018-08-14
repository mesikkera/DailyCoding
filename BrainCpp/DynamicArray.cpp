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
void DynamicArray::SetAt(int index, int value)
{
    arr[index] = value;
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