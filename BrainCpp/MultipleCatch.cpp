#include "MyException.h"
#include <iostream>
using namespace std;

void A();

int main()
{
    try
    {
        A();
    }
    catch(MemoryException& ex)
    {
        cout << "Memory Exception!" << endl;
    }
    catch(OutOfRangeException& ex)
    {
        cout << "Out of Range Exception!" << endl;
    }
    catch(...)
    {
        cout << "ETC" << endl;
    }
    return 0;
}

void A()
{
    throw 100;
    // throw OutOfRangeException(NULL, 0);
}