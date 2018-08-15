#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main()
{
    typedef tuple<string, int, double> Data;

    Data data1("Ronaldo", 7, 55);

    string my_str = "";
    int my_int = 0;

    tie(my_str, my_int, ignore) = data1;

    cout << my_str << ", " << my_int << endl;

    return 0;
}