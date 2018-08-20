#pragma once
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

// ���� �迭 Ŭ����
class DynamicArray
{
public:
	// ������, �Ҹ���
	DynamicArray(int arraySize);
	~DynamicArray();

	// ������
	void SetAt(int index, int value);
	int GetAt(int index) const;
	int GetSize() const;

protected:
	int* arr;	// �Ҵ�� �޸� ����
	int size;	// �迭�� ���� ����
};

#endif // !DYNAMICARRAY_H
