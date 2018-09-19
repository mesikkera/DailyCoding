#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Pred(int n)
{
    return 30 <= n && n <= 40;
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

    vector<int>::iterator iter_end;
    iter_end = remove(v.begin(), v.end(), 30);

    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    cout << "remove 후 [v.begin(), iter_end) 순차열 : ";
    for(vector<int>::iterator iter = v.begin(); iter != iter_end; ++iter)
        cout << *iter << " ";
    cout << endl;

// remove() 후의 erase() 멤버 함수 사용
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(30);
    v1.push_back(50);

    cout << "v1 : ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] << " ";
    cout << endl;

    iter_end = remove(v1.begin(), v1.end(), 30);

    cout << "v1 : ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] << " ";
    cout << endl;

    // 구간 [v1.begin(), v1.end())의 원소를 실제로 삭제
    v1.erase(iter_end, v1.end());
    cout << "v1 : ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] << " ";
    cout << endl;

// remove_if() 알고리즘
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);

    cout << "v2 : ";
    for(vector<int>::size_type i = 0; i < v2.size(); ++i)
        cout << v2[i] << " ";
    cout << endl;

    iter_end = remove_if(v2.begin(), v2.end(), Pred);

    cout << "[v.begin(), iter_end) : ";
    for(vector<int>::iterator iter = v2.begin(); iter != iter_end; ++iter)
        cout << *iter << " ";
    cout << endl;

// remove_copy() 알고리즘
    vector<int> v3;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);
    v3.push_back(40);
    v3.push_back(50);

    vector<int> v4(5);
    
    iter_end = remove_copy(v3.begin(), v3.end(), v4.begin(), 30);

    cout << "v3 : ";
    for(vector<int>::size_type i = 0; i < v3.size(); ++i)
        cout << v1[i] << " ";
    cout << endl;

    cout << "v4 : ";
    for(vector<int>::size_type i = 0; i < v4.size(); ++i)
        cout << v4[i] << " ";
    cout << endl;

    cout << "[v2.begin(), iter_end) : ";
    for(vector<int>::iterator iter = v4.begin(); iter != iter_end; ++iter)
        cout << *iter << " ";
    cout << endl;
    return 0;
}