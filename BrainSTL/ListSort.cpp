#include <iostream>
#include <list>
using namespace std;

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

    return 0;
}