#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int data1[10]{0, };                                     // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    // fill_n (수정할 배열의 시작 위치, 변경할 요소의 개수, 변경할 값)
    fill_n(data1, 2, 10);                                   // {10, 10, 0, 0, 0, 0, 0, 0, 0, 0}
    fill_n(data1 + 4, 3, 20);                               // {10, 10, 0, 0, 20, 20, 20, 0, 0, 0}

    cout << " == Result Data1 == " << endl;

    for (int i = 0; i < 10; i++)
        cout << data1[i] << ", ";

    vector<int> data2({0, 1, 2, 3, 4, 5, 6, 7});            // {1, 2, 3, 4, 5, 6, 7}
    fill_n(data2.begin(), data2.size() - 1, 30);            // {30, 30, 30, 30, 30, 30, 30, 7}
    fill_n(data2.begin(), 4, 40);                           // {40, 40, 40, 40, 30, 30, 30, 7}

    cout << endl << endl << " == Result Data2 == " << endl;

    for (int i = 0, size = data2.size(); i < size; i++)
        cout << data2.at(i) << ", ";

    return 0;
}