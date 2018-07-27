#include <iostream>
using namespace std;

int main()
{
    int a = 123;
    int b = 456;
    int c = 789;

    int* pointer1;
    int * pointer2;
    int *pointer3;

    pointer1 = &a;
    pointer2 = &b;
    pointer3 = &c;

    cout << "&a = " << &a << endl;
    cout << "pointer1 = " << pointer1 << endl;
    cout << "&pointer1 = " << &pointer1 << endl;
    cout << "*pointer1 = " << *pointer1 << endl; 
    cout << endl;
    cout << "&b = " << pointer2 << endl;
    cout << "&c = " << pointer3 << endl;

    return 0;
}