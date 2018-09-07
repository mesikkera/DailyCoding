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

    return 0;
}