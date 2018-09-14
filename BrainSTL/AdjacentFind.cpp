#include <iostream>
#include <vector>
#include <algorithm>    // 알고리즘 헤더
using namespace std;

// 이항 조건자 
bool Pred(int a, int b)
{
    return abs(b - a) > 10;
}

bool Pred2(int n)
{
    return 25 < n;
}

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);
    v.push_back(50);

    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    vector<int>::iterator iter;
    // 구간 [v.begin(), v.end()) 에서 현재 원소와 다음 원소가 같아지는 첫 원소 반복자를 반환 
    iter = adjacent_find(v.begin(), v.end());

    if(iter != v.end())     // 같은 원소가 없다면 구간의 끝 반복자 반환
        cout << *iter << endl;

    for(; iter != v.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

// adjacent_fint() 알고리즘의 반환 반복자
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    vector<int>::iterator iter_b = v1.begin();
    vector<int>::iterator iter_e = v1.begin() + 2;
    // 구간 [iter_b, iter_e) 의 순차열은 10, 20 이므로
    // 찾는 원소가 없어 iter는 구간의 끝인 iter_e입니다.
    iter = adjacent_find(iter_b, iter_e);

    // 모두 맞는지 확인
    if(iter != iter_e)
        cout << *iter << endl;
    if(iter != v.end())
        cout << *iter << endl;

// adjacent_find() 조건자 버전
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(50);
    v2.push_back(90);

    for(vector<int>::size_type i = 0; i < v2.size(); ++i)
        cout << v2[i] << " ";
    cout << endl;

    iter = adjacent_find(v2.begin(), v2.end(), Pred);

    if(iter != v2.end())
        cout << *iter << endl;

    for ( ; iter != v2.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

// count() 알고리즘 
    // 구간 [v2.begin(), v2.end())에서 30 원소의 개수를 반환
    int n = count(v2.begin(), v2.end(), 30);
    cout << "30의 개수 : " << n << endl;

// 조건자 버전의 count_if()
    // 구간 [v2.begn(), v2.end()) 에서 25보다 큰 원소의 개수를 반환
    int n2 = count_if(v2.begin(), v2.end(), Pred2);
    cout << "25보다 큰 원소의 개수 : " << n2 << endl;
    return 0;
}