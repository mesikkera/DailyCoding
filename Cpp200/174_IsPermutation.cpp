#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
    array<int, 5> data1 = {5, 3, 1, 7, 9};
    array<int, 5> data2 = {1, 3, 5, 7, 9};
    array<int, 7> data3 = {2, 2, 1, 3, 5, 7, 9};

    cout << boolalpha;
    // is_permutation(): 정렬되지 않은 두 컨테이너의 요소(또는 일부 영역)를 비교
    // 지정한 요소의 범위가 동일-> true 리턴
    cout << "data1 == data2 : " << is_permutation(data1.begin(), data1.end(), data2.begin()) << endl;
    cout << "data1 == data3 : " << is_permutation(data1.begin(), data1.end(), data3.begin()) << endl;
    // data3.begin() + 2: data3의 세 번째 위치부터 비교
    cout << "data1 == data2 (+2) : " << is_permutation(data1.begin(), data1.end(), data3.begin() + 2) << endl;

    return 0;
}