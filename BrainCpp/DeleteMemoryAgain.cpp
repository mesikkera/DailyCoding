#include <iostream>
using namespace std;

int main()
{
    short* p = new short [100];

    cout << "p = " << p << endl;

    delete [] p;

    cout << "p = " << p << endl;

    delete [] p;

    return 0;
}