#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> ms;
    multiset<int>::iterator iter;

    ms.insert(50);
    ms.insert(30);
    ms.insert(80);
    ms.insert(80);      // 80 중복
    ms.insert(30);      // 30 중복
    ms.insert(70);
    iter = ms.insert(10);

    cout << "iter의 원소 : " << *iter << endl;

    for(iter = ms.begin(); iter != ms.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

// multiset의 찾기 관련 함수

    cout << "30원소의 개수 : " << ms.count(30) << endl;     // 30 원소의 개수

    iter = ms.find(30);     // 30 첫 번째 원소의 반복자
    cout << "iter : " << *iter << endl;

    multiset<int>::iterator lower_iter;
    multiset<int>::iterator upper_iter;

    lower_iter = ms.lower_bound(30);        // 30 순차열의 시작 반복자
    upper_iter = ms.upper_bound(30);        // 30 순차열의 끝 반복자
    cout << "lower_iter: " << *lower_iter << ", " << "upper_iter: " << *upper_iter << endl;

    cout << "구간 [lower_iter, upper_iter)의 순차열: ";
    for(iter = lower_iter; iter != upper_iter; ++iter)
        cout << *iter << " ";
    cout << endl;

// multiset의 equal_range()

    // multiset의 반복자 쌍(pair) 객체 생성
    pair<multiset<int>::iterator, multiset<int>::iterator> iter_pair;
    iter_pair = ms.equal_range(30);

    for(iter = iter_pair.first; iter != iter_pair.second; ++iter)
        cout << *iter << " ";
        // [iter_pair.first, iter_pair.second] 구간의 순차열
    cout << endl;

    return 0;
}