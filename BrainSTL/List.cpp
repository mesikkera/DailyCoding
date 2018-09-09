#include <iostream>
#include <list>
using namespace std;

bool Predicate(int n)       // 단항 조건자
{
    return 10 <= n && n <=30;
}

bool Predicate2(int first, int second)
{
    return second - first <= 0;
}

int main()
{
    list<int> lt;

    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);

    list<int>::iterator iter;
    for(iter = lt.begin(); iter != lt.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    lt.push_front(100);
    lt.push_front(200);

    for(iter = lt.begin(); iter != lt.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    // list의 remove()
    list<int> lt2;

    lt2.push_back(10);
    lt2.push_back(20);
    lt2.push_back(30);
    lt2.push_back(40);
    lt2.push_back(50);
    lt2.push_back(10);
    lt2.push_back(10);

    list<int>::iterator iter2;
    for(iter2 = lt2.begin(); iter2 != lt2.end(); ++iter2)
        cout << *iter2 << " ";
    cout << endl;

    lt2.remove(10);     // 10 원소의 노드를 모두 제거
    for(iter2 = lt2.begin(); iter2 != lt2.end(); ++iter2)
        cout << *iter2 << " ";
    cout << endl;

    // list의 remove_if()
    list<int> lt3;

    lt3.push_back(10);
    lt3.push_back(20);
    lt3.push_back(30);
    lt3.push_back(40);
    lt3.push_back(50);

    list<int>::iterator iter3;
    for(iter = lt3.begin(); iter != lt3.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    lt3.remove_if(Predicate);       // 조건자가 참인 원소를 모두 제거
    for(iter = lt3.begin(); iter != lt3.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    // list의 reverse()
    list<int> lt4;

    lt4.push_back(10);
    lt4.push_back(20);
    lt4.push_back(30);
    lt4.push_back(40);
    lt4.push_back(50);

    list<int>::iterator iter4;
    for(iter4 = lt4.begin(); iter4 != lt4.end(); ++iter4)
        cout << *iter4 << " ";
    cout << endl; 

    lt4.reverse();

    for(iter4 = lt4.begin(); iter4 != lt4.end(); ++iter4)
        cout << *iter4 << " ";
    cout << endl; 

    // list의 unique()
    list<int> lt5;

    lt5.push_back(10);
    lt5.push_back(10);
    lt5.push_back(20);
    lt5.push_back(30);
    lt5.push_back(30);
    lt5.push_back(30);
    lt5.push_back(40);
    lt5.push_back(50);
    lt5.push_back(10);

    list<int>::iterator iter5;
    for(iter5 = lt5.begin(); iter5 != lt5.end(); ++iter5)
        cout << *iter5 << " ";
    cout << endl;

    // 인접한 원소를 유니크하게 만든다.
    // unique() 멤버 함수로 모든 원소를 유일하게 만들고자 한다면
    // 원소를 정렬한 후 unique()를 수행하면 된다.
    lt5.unique();

    for(iter5 = lt5.begin(); iter5 != lt5.end(); ++iter5)
        cout << *iter5 << " ";
    cout << endl;

    // list의 조건자 버전 unique()
    list<int> lt6;

    lt6.push_back(10);
    lt6.push_back(10);
    lt6.push_back(20);
    lt6.push_back(30);
    lt6.push_back(30);
    lt6.push_back(30);
    lt6.push_back(40);
    lt6.push_back(50);
    lt6.push_back(10);

    list<int>::iterator iter6;
    for(iter6 = lt6.begin(); iter6 != lt6.end(); ++iter6)
        cout << *iter6 << " ";
    cout << endl;

    lt6.unique(Predicate2);
    for(iter6 = lt6.begin(); iter6 != lt6.end(); ++iter6)
        cout << *iter6 << " ";
    cout << endl;

    return 0;
}