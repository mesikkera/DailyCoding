#include <iostream>

using namespace std;

struct Data1
{
    Data1(int x) : number(x) {}

    int number;
};

struct Data2
{
    Data2()
    {
        number = 10;
    }

    int number;
} data2;

int main()
{
    Data1 data1(2);
    cout << "Data1 Number : " << data1.number << endl;
    cout << "Data2 Number : " << data2.number << endl;

    return 0;
}