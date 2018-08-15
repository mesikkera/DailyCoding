#include <iostream>
#include <tuple>

using namespace std;

struct TupleExam {
    TupleExam(tuple<int, string>) {
        cout << "Argument pass by Tuple" << endl;
    }

    TupleExam(int n, string s) { 
        cout << "Argument pass by piecewise_construct" << endl;
    }
};

int main()
{
    tuple<int, string> data(1, "str");

    pair<TupleExam, TupleExam> data1(data, data);
    pair<TupleExam, TupleExam> data2(piecewise_construct, data, data);
    pair<TupleExam, TupleExam> data3(make_tuple(2, "str"), make_tuple(2, "str"));
    pair<TupleExam, TupleExam> data4(piecewise_construct, make_tuple(2, "str"), make_tuple(2, "str"));

    return 0;
}