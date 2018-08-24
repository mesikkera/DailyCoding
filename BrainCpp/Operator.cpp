#include "ComplexClass.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& o, const Complex& right)
{
    o << right.Real() << showpos << right.Imaginary() << "i" << noshowpos;
    return o;
}

int main()
{
    Complex c1(10, 5);

    cout << c1 << endl;

    return 0;
}