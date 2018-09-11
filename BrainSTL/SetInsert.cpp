#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;     // 정수 원소를 저장하는 기본 정렬 기준이 less인 빈 컨테이너 생성

    s.insert(50);   // 랜덤으로 원소(key)를 삽입
    s.insert(30);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(70);
    s.insert(90);

    set<int>::iterator iter;    // 기본 정렬 기준이 less인 set의 양방향 반복자
    for(iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    // 중복된 원소(key) 삽입
    s.insert(50);
    s.insert(50);

    for(iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    return 0;
}