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

    return 0;
}