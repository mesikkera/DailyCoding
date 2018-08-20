#pragma once
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

// 동적 배열 클래스
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
	int* arr;	// 할당된 메모리 보관
	int size;	// 배열의 길이 보관
};

#endif // !DYNAMICARRAY_H
