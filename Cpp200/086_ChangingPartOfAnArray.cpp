#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int data1[10] { 0, };                   // {0,0,0,0,0,0,0,0,0,0}
    // fill(수정할 배열 영역의 시작위치, 마지막 위치, 수정할 값)
    fill(data1, data1 + 3, 10);             // {10, 10, 10, 0, 0, 0, 0, 0, 0, 0}
    fill(data1 + 4, data1 + 8, 20);         // {10, 10, 10, 0, 20, 20, 20, 20, 0, 0}

    cout << "== Result data1 ==" << endl;

    cout << "{ ";
    for (int i = 0; i < 10; i++)
        cout << data1[i] << ", ";
    cout << "}";

    vector<int> data2({0, 1, 2, 3, 4, 5, 6, 7});
    fill(data2.begin(), data2.begin() + 3, 30);

    cout << endl << endl << " == Result Data2 == " << endl;

    for(int i = 0, size = data2.size(); i < size; i++)
        cout << data2.at(i) << ", ";
    
    return 0;
}