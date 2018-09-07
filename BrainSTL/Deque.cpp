#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
    deque<int> dq;

    for(deque<int>::size_type i = 0; i < 10; ++i)
        dq.push_back((i+1) * 10);

    for(deque<int>::size_type i = 0; i < dq.size(); ++i)
        cout << dq[i] << " ";
    cout << endl;

    vector<int> v1(4, 100);      // 100으로 초기화한 4개의 원소를 갖는 컨테이너 V
    deque<int> dq1(4, 100);      // 100으로 초기화한 4개의 원소를 갖는 컨테이너 dq
    
    v1.push_back(200);          // v1에 200 추가
    dq1.push_back(200);         // dq1에 200 추가

    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] << " ";
    cout << endl;

    for(deque<int>::size_type i = 0; i < dq1.size(); ++i)
        cout << dq1[i] << " ";
    cout << endl;

    // deque의 push_front()
    deque<int> dq2;

    dq2.push_back(10);
    dq2.push_back(20);
    dq2.push_back(30);
    dq2.push_back(40);
    dq2.push_back(50);

    for(deque<int>::size_type i = 0; i < dq2.size(); ++i)
        cout << dq2[i] << " ";
    cout << endl;

    dq2.push_front(100);        // 앞쪽에 추가
    dq2.push_front(200);        
    for(deque<int>::size_type i = 0; i < dq2.size(); ++i)
        cout << dq2[i] << " ";
    cout << endl;

    // deque의 반복자
    deque<int> dq3;

    dq3.push_back(10);
    dq3.push_back(20);
    dq3.push_back(30);
    dq3.push_back(40);
    dq3.push_back(50);

    deque<int>::iterator iter;
    for(iter = dq3.begin(); iter != dq3.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    iter = dq.begin() + 2;      // 반복자에 + 2 한다.
    cout << *iter << endl;

    iter += 2;                  // 반복자에 +2 한다.
    cout << *iter << endl;

    iter -= 3;                  // 반복자에 -3 한다.
    cout << *iter << endl;

    // deque의 insert()
    deque<int> dq4;

    for(int i = 0; i < 10; i++)
        dq4.push_back((i+1) * 10);

    deque<int>::iterator iter2;
    deque<int>::iterator iter3;
    for(iter2 = dq4.begin(); iter2 != dq4.end(); ++iter2)
        cout << *iter2 << " ";
    cout << endl;

    iter2 = dq4.begin() + 2;
    iter3 = dq4.insert(iter2, 500);
    cout << *iter3 << endl;

    for(iter2 = dq4.begin(); iter2 != dq4.end(); ++iter2)
        cout << *iter2 << " ";
    cout << endl;

    return 0;
}