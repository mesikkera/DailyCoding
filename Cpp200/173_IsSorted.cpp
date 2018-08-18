#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

int main()
{
    list<int> data1 = {5, 3, 1, 7, 9};
    list<string> data2 = {"ef", "ab", "cd", "ij", "gh"};

    cout << boolalpha;
    // 리스트 정렬 여부 확인
    cout << "data1 sort : " << is_sorted(data1.begin(), data1.end()) << endl;
    cout << "data2 sort : " << is_sorted(data2.begin(), data2.end()) << endl;

    // 리스트 정렬
    data1.sort();
    data2.sort();

    // 리스트 정렬 여부 확인
    // 정렬: true 리턴, 비정렬: false 리턴
    cout << "data1 sort : " << is_sorted(data1.begin(), data1.end()) << endl;
    cout << "data2 sort : " << is_sorted(data2.begin(), data2.end()) << endl;

    cout << "== data1 ==" << endl;
    for (auto i : data1)
        cout << i << ", ";

    cout << endl << "== data2 ==" << endl;
    for (auto i : data2)
        cout << i << ", ";

    return 0; 
}