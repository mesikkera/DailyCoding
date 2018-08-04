#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Input Integer: " ;
    cin >> size;

    // 메모리 할당
    int* arr = new int [size];

    cout << "Input Integer: ";
    for (int i = 0; i < size; ++i)
        cin >> arr[i];

    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    float ave = (float)sum / (float)size;
    cout << "Sum = " << sum << ", Average = " << ave << endl;

    // 메모리 해제
    delete[] arr;

    return 0;
}