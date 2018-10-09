#include <iostream>
using namespace std;

int main()
{
    using salary = double;
    salary peter = 100.12;
    salary &sangwon = peter;
    cout << "Peter's memory address = " << &peter << endl;
    cout << "sangwon's memory address = " << &sangwon << endl;
    return 0;
}