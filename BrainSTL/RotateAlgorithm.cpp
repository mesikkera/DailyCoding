#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

    vector<int>::iterator middle = v.begin() + 2;
    // 모든 원소를 왼쪽으로 2만큼 회전
    rotate(v.begin(), middle, v.end());

    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

// rotate_copy() 알고리즘
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    cout << "v1 : ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] << " ";
    cout << endl;

    vector<int> v2(5);
    vector<int>::iterator middle1 = v1.begin() + 2;
    vector<int>::iterator iter_end;
    // 모든 원소를 왼쪽으로 2만큼씩 회전하여 [v2.begin(), iter_end) 순차열에 복사
    iter_end = rotate_copy(v1.begin(), middle, v1.end(), v2.begin());
    
    cout << "v2 : ";
    for(vector<int>::iterator iter = v2.begin(); iter != iter_end; ++iter)
        cout << *iter << " ";
    cout << endl;

    return 0;
}