#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> result;

    // copy_n(): 일부 배열만 복사할 때 사용
    // copy_n(복사할 대상, 원하는 개수, 복사될 배열);
    copy_n(data, 5, back_inserter(result));

    cout << "== result ==" << endl;
    for (auto i : result)
        cout << i << ", ";

    return 0;
}