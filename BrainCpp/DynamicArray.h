#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

// 동적인 배열 클래스
class DynamicArray 
{
public:
    // 생성자, 소멸자
    DynamicArray(int arraySize);
    ~DynamicArray();

    // 접근자
    void SetAt(int index, int value);
    int GetAt(int index) const;
    int GetSize() const;

protected:
    int* arr;
    int size;    
};

#endif