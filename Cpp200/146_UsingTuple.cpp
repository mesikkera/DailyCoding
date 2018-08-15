#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main()
{
    typedef tuple<string, int, double> Data;

    // data1의 선언방식과 data2의 선언방식은 동일의미
    Data data1("문자열", 10, 1.2);
    auto data2 = make_tuple("make_tuple", 123, 1.23);

    cout << get<0>(data1) << ", " << get<1>(data1) << ", " << get<2>(data1) << endl;
    cout << get<0>(data2) << ", " << get<1>(data2) << ", " << get<2>(data2) << endl;

    return 0;
}