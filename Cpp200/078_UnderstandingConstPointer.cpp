#include <iostream>

using namespace std;

int main()
{
    int number1 = 10;
    int number2 = 20;

    int const *ptr1;
    ptr1 = &number1;
    // ptr1 = number1;
    ptr1 = &number2;

    int *const ptr2 = &number1;
    *ptr2 = number2;
    //*ptr2 = &number2;

    return 0;
}