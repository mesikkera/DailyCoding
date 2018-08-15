#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main()
{
    // 튜플은 같은 형태끼리 비교연산이 가능하다.
    
    tuple<int, string> data1(1, "def");
    tuple<int, string> data2(1, "abc");

    if (data1 > data2)
        cout << "data1 > data2" << endl;
    else 
        cout << "data1 < data2" << endl;

    tuple<double, string> data3(1.0, "def");
    tuple<double, string, int> data4(2.0, "abc", 3);

    return 0;
}