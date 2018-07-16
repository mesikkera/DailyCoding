#include <iostream>

using namespace std;

// extern int g_number = 100;
int g_number = 100;

int Func1()
{
    return g_number++;
}

int Func2()
{
    return g_number++;
}

int main()
{
    int number = g_number++;

    cout << "Main Number : " << number << endl;
    cout << "Func1 Number : " << Func1() << endl;
    cout << "Func2 Number : " << Func2() << endl;

    return 0;
}