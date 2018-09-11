#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;

    s.insert(50);
    s.insert(30);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(70);
    s.insert(90);

    set<int>::iterator iter;
    for(iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "원소 50의 개수 : " << s.count(50) << endl;
    cout << "원소 100의 개수 : " << s.count(100) << endl;

// set의 find()
    iter = s.find(30);      // 30의 반복자를 반환
    if(iter != s.end())
        cout << *iter << "이 s에 있다." << endl;
    else 
        cout << "s에 30이 없다" << endl;

// set의 정렬 기준을 사용한 값 비교

    // 30과 50의 비교
    cout << (!s.key_comp()(30, 50) && !s.key_comp()(50, 30)) << endl;
    // 30과 30의 비교
    cout << (!s.key_comp()(30, 30) && !s.key_comp()(30, 30)) << endl;

// set의 lower_bound(), upper_bound()
    for(iter = s.begin(); iter != s.end(); ++iter)
            cout << *iter << " ";
        cout << endl; 
    set<int>::iterator iter_lower;
    set<int>::iterator iter_upper;

    iter_lower = s.lower_bound(30);
    iter_upper = s.upper_bound(30);
    cout << *iter_lower << endl;
    cout << *iter_upper << endl;

    iter_lower = s.lower_bound(55);
    iter_upper = s.lower_bound(55);
    if(iter_lower != iter_upper)
        cout << "55가 s에 있음!" << endl;
    else 
        cout << "55가 s에 없음!" << endl;

// set의 equal_range()
    // 반복자 쌍의 pair 객체
    pair<set<int>::iterator, set<int>::iterator> iter_pair;

    iter_pair = s.equal_range(30);
    cout << *iter_pair.first << endl;
    cout << *iter_pair.second << endl;

    iter_pair = s.equal_range(55);
    if(iter_pair.first != iter_pair.second)
        cout << "55가 s에 있음!" << endl;
    else 
        cout << "55가 s에 없음!" << endl;

    return 0;
}