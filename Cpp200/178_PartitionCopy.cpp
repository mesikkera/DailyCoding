#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool IsOdd(int i) { return (i % 2) == 1; }

int main()
{
    vector<int> data1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    vector<int> odd;
    vector<int> even;

    // partition_copy(시작위치, 끝위치, 조건부합 컨테이너, 조건미부합 컨테이어, 분리조건)
    // data1의 시작부터 끝까지 순회하면서 IsOdd 일경우 odd 컨테이너에, IsOdd가 아닐경우 even에 데이터 추가
    partition_copy(data1.begin(), data1.end(), back_inserter(odd), back_inserter(even), IsOdd);

    cout << "== 홀수 ==" << endl;
    for (int x : odd)
        cout << x << ", ";

    cout << endl << "== 짝수 ==" << endl;
    for (int x : even)
        cout << x << ", ";

    return 0;
}