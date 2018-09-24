#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int Multi(int left, int right)
{
    return left * right;
}

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    vector<int> v2(5);
    vector<int>::iterator iter_end;
    iter_end = partial_sum(v.begin(), v.end(), v2.begin());

    cout << "v2: ";
    for(vector<int>::size_type i = 0; i < v2.size(); ++i)
        cout << v2[i] << " ";
    cout << endl;

// 함수류 버전 partial_sum 알고리즘
    vector<int> v3(5);
    iter_end = partial_sum(v.begin(), v.end(), v3.begin(), Multi);

    cout << "v3: ";
    for(vector<int>::size_type i = 0; i < v3.size(); ++i)
        cout << v3[i] << " ";
    cout << endl;

    return 0;
}