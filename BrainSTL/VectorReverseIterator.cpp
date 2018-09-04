#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    // STL 모든 컨테이너는 반복자 어댑터 reverse_iterator를 typedef 타입으로 정의하며
    // rbegin(), rend()로 컨테이너의 역방향 반복자를 반환
    // vector<int>::reverse_iterator : vector에 정의되어 있는 reverse_iterator 어댑터의 typedef 타입입니다.
    vector<int>::reverse_iterator riter(v.rbegin());        // v.rbegin() : v의 첫 원소를 가리키는 역방향 반복자 반환
    for( ; riter != v.rend(); ++riter)                      // v.rend() : v의 마지막 원소를 가리키는 역방향 반복자 반환
        cout << *riter << " ";
    cout << endl;

    return 0;
}