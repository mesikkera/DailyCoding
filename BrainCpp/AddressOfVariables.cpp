#include <iostream>
using namespace std;

int main()
{
    char c = 'B';
    int i = 19;
    float f = 4.5f;

    cout << "&c = " << &c << endl;
    cout << "(int*)&c = " << (int*)&c << endl;
    cout << "&i = " << &i << endl;
    cout << "&f = " << &f << endl;

    return 0;
}