#include <iostream>

using namespace std;

int main()
{
    int number1 = 10;
    int *pointer1 = &number1;

    double number2 = 23.4;
    double *pointer2 = &number2;

    cout << "number1 : " << number1 << " (size: " << sizeof(number1) << ")" << endl;
    cout << "pointer1: " << pointer1 << " (size: " << sizeof(pointer1) << ")" << endl;

    cout << "number2 : " << number2 << " (size: " << sizeof(number2) << ")" << endl;
    cout << "pointer2: " << pointer2 << " (size: " << sizeof(pointer2) << ")" << endl;

    return 0;
}