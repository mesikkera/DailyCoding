#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    auto data1 = 1;
    // decltype: 컴파일러가 자동으로 타입을 추론
    // 인자로 받은 자료형에 맞춰 다른 변수의 자료형을 지정
    decltype(data1) data2 = 2;

    auto data3 = 3.4;
    decltype(data2 + data3) data4 = 3;

    cout << "Data1 : " << data1 << ", " << typeid(data1).name() << endl;
    cout << "Data2 : " << data2 << ", " << typeid(data2).name() << endl;
    cout << "Data3 : " << data3 << ", " << typeid(data3).name() << endl;
    cout << "Data4 : " << data4 << ", " << typeid(data4).name() << endl;

    return 0;
}