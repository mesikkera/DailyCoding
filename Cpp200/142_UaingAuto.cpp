#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int GetInt() { return 1; }
double GetDouble() { return 1.11; }
string GetString() { return "3"; } 

auto add(int x, int y) -> int
{
    return x + y;
}

int main()
{
    auto data1 = GetInt();
    auto data2 = GetDouble();
    auto data3 = GetString();
    auto data4 = add(5.1, 10.2);

    cout << "Data1 : " << data1 << ", " << typeid(data1).name() << endl;
    cout << "Data2 : " << data2 << ", " << typeid(data2).name() << endl;
    cout << "Data3 : " << data3 << ", " << typeid(data3).name() << endl;
    cout << "Data4 : " << data4 << ", " << typeid(data4).name() << endl;

    return 0;
}