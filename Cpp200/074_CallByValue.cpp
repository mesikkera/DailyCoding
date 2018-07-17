#include <iostream>

using namespace std;

void Func(int arg)
{
    cout << "Before Addition : " << arg << endl;
    arg += 10;
    cout << "After Addition : " << arg << endl;
}

int main()
{
    int year = 10;

    Func(year);

    cout << "After Call By Value : " << year << endl;

    return 0;
}