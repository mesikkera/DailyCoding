#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main()
{
    tuple<int, double> data1(1, 2.1);
    tuple<double, string> data2(3.4, "Jeju-do");

    auto data3 = tuple_cat(data1, data2);

    cout << get<0>(data3) << ", " << get<1>(data3) << ", " << get<2>(data3) << ", " << get<3>(data3) << endl;

    return 0;
}