#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    vector<int> data1 = {1, 3, 5, 7, 9};
    vector<int> data2 = {2, 4, 6, 7, 9};
    vector<int> diff1;
    vector<int> diff2;

    // set_dirrerence(): 2개의 컨테이너의 내용을 비교하여 새로운 컨테이너에 그 차이를 저장. 
    set_difference(data1.begin(), data1.end(), data2.begin(), data2.end(), inserter(diff1, diff1.begin()));
    set_difference(data1.begin() + 2, data1.end(), data2.begin() + 2, data2.end(), inserter(diff2, diff2.begin()));

    cout << "== diff1 ==" << endl;
    for (auto i : diff1)
        cout << i << ", ";

    cout << endl << "== diff2 ==" << endl;
    for (auto i : diff2)
        cout << i << ", ";

    return 0;
}