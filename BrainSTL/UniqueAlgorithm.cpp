#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Pred(int left, int right)
{
    return abs(right - left) < 10;
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
    v.push_back(30);
    v.push_back(50);

    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    vector<int>::iterator iter_end;
    iter_end = unique(v.begin(), v.end());

    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    cout << "[v.begin(), iter_end) : ";
    for(vector<int>::iterator iter = v.begin(); iter != iter_end; ++iter)
        cout << *iter << " ";
    cout << endl;

// 조건자 버전 unique() 알고리즘
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(11);
    v1.push_back(30);
    v1.push_back(32);
    v1.push_back(40);
    v1.push_back(50);

    cout << "v1 : ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] << " ";
    cout << endl;

    iter_end = unique(v1.begin(), v1.end(), Pred);

    cout << "v1 : ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] << " ";
    cout << endl;

    cout << "[v1.begin(), iter_end) : ";
    for(vector<int>::iterator iter = v1.begin(); iter != iter_end; ++iter)
        cout << *iter << " ";
    cout << endl;

    return 0;
}