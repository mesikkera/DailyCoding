#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Pred(int n)
{
    return n < 40;
}

int main()
{
    vector<int> v;
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);
    v.push_back(60);

    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    vector<int>::iterator iter_sep;
    // 40 원소를 기준으로 미만과 이상을 분류
    iter_sep = partition(v.begin(), v.end(), Pred);

    cout << "40 미만의 순차열 : ";
    for(vector<int>::iterator iter = v.begin(); iter != iter_sep; ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "40 이상의 순차열 : "; 
    for(vector<int>::iterator iter = iter_sep; iter != v.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

// stable_partition() 알고리즘
    vector<int> v1;
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(60);

    cout << "v1 : ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] << " ";
    cout << endl;

    // 40 원소를 기준으로 미만과 이상을 분류
    iter_sep = stable_partition(v1.begin(), v1.end(), Pred);

    cout << "40 미만의 순차열 : ";
    for(vector<int>::iterator iter = v1.begin(); iter != iter_sep; ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "40 이상의 순차열 : "; 
    for(vector<int>::iterator iter = iter_sep; iter != v1.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    return 0;
}