#include <iostream>

using namespace std;
int main()
{
    int value = 100;
    int *pointerValue = &value;
    cout << value << endl;
    cout << &value << endl;
    cout << pointerValue << endl;
    cout << *pointerValue << endl;
    cout << &pointerValue << endl;
    int** ppointerValue = &pointerValue;
}