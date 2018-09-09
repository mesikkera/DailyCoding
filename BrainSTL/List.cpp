#include <iostream>
#include <list>
using namespace std;

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

    return 0;
}