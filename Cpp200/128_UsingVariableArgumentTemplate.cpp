#include <iostream>
#include <string>

using namespace std;

void Type1(string msg, int no, double value)
{
    cout << msg << ", Error Number : " << no << ", Error Value : " << value << endl;
}

void Type2(int no, double value)
{
    cout << no << ", Error Value : " << value << endl;
}

// ... : 인자의 갯수가 정해지지 않았다.
template<typename... T>
void PrintLog(T... arg0)
{
    // 추가 작업
    Type1(arg0...);
    // Type2(arg0,l;)
}

int main()
{
    PrintLog<string , int, double>("Warning", 100, 22.5);
    // PrintLog<int, double>(101, 55.6);

    return 0;
}