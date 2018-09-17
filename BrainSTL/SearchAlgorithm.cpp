#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Pred(int left, int right)
{
    return abs(right - left) <= 5;
}

int main()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    v1.push_back(60);
    v1.push_back(70);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    vector<int> v2;
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);

    vector<int>::iterator iter;
    iter = search(v1.begin(), v1.end(), v2.begin(), v2.end());
    if(iter != v1.end())
    {
        // 일치하는 첫 번째 순차열의 첫 원소의 반복자 iter
        cout << "iter : " << *iter << endl;
        cout << "iter - 1 : " << *(iter - 1) << endl;
        cout << "iter + 1 : " << *(iter + 1) << endl;
    }

// search_n() 알고리즘
    vector<int> v3;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);
    v3.push_back(30);
    v3.push_back(30);
    v3.push_back(40);
    v3.push_back(50);

    iter = search_n(v3.begin(), v3.end(), 3, 30);
    if(iter != v3.end())
    {
        cout << "iter : " << *iter << endl;
        cout << "iter-1 : " << *(iter - 1) << endl;
        cout << "iter+1 : " << *(iter + 1) << endl;
    }

// 조건자 버전 search_n() 알고리즘
    vector<int> v4;
    v4.push_back(10);
    v4.push_back(20);
    v4.push_back(32);
    v4.push_back(28);
    v4.push_back(33);
    v4.push_back(40);
    v4.push_back(50);

    iter = search_n(v4.begin(), v4.end(), 3, 30, Pred);
    if(iter != v3.end())
    {
        cout << "iter : " << *iter << endl;
        cout << "iter-1 : " << *(iter - 1) << endl;
        cout << "iter+1 : " << *(iter + 1) << endl;
    }
 
    return 0;
}