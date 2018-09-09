#include <iostream>
#include <list>
using namespace std;

struct Greater
{
    bool operator()(int left, int right) const 
    {
        return left > right;
    }
};

int main()
{
    list<int> lt;
    lt.push_back(20);
    lt.push_back(10);
    lt.push_back(50);
    lt.push_back(30);
    lt.push_back(40);

    list<int>::iterator iter;
    for(iter = lt.begin(); iter != lt.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    // sort()
    // 정렬의 기준은 오름차순으로 < 연산한 결과.
    // 비교 대상인 두 원소를 < 연산하여 정렬을 수행
    // < 연산자는 less 조건자의 연산 결과와 같다.
    lt.sort();      // 오름차순 정렬

    for(iter = lt.begin(); iter != lt.end(); ++iter)
        cout << *iter << " ";


    // list의 조건자 버전 sort()
    list<int> lt2;
    lt2.push_back(20);
    lt2.push_back(10);
    lt2.push_back(50);
    lt2.push_back(30);
    lt2.push_back(40);

    list<int>::iterator iter2;
    for(iter2 = lt2.begin(); iter2 != lt2.end(); ++iter2)
        cout << *iter2 << " ";
    cout << endl;

    // 조건자 greater를 사용하여 내림차순 정렬
    lt2.sort(greater<int>());
    for(iter2 = lt2.begin(); iter2 != lt2.end(); ++iter2)
        cout << *iter2 << " ";
    cout << endl;

    // 조건자 less를 사용하여 오름차순 정렬
    lt2.sort(less<int>());
    for(iter2 = lt2.begin(); iter2 != lt2.end(); ++iter2)
        cout << *iter2 << " ";
    cout << endl;

    // 사용자 정의 조건자를 사용하여 내림차순 정렬
    lt2.sort(Greater()); 
    for(iter2 = lt2.begin(); iter2 != lt2.end(); ++iter2)
        cout << *iter2 << " ";
    cout << endl;

    return 0;
}