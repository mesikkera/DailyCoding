#include <iostream>
#include <vector>
#include <algorithm>        // find 사용
using namespace std;

bool Pred(int left, int right)
{
    return left <= right;
}

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator iter;
    iter = find(v.begin(), v.end(), 20);           // [begin, end)에서 20 찾기
    cout << *iter << endl;

    iter = find(v.begin(), v.end(), 100);
    if(iter == v.end())     // 100이 없으면 iter == v.end()임
        cout << "100 is not found!" << endl;

// find_end() 알고리즘 이용해 컨테이너 판단
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

    iter = find_end(v1.begin(), v1.end(), v2.begin(), v2.end());
    if(iter != v1.end())
    {
        // 일치하는 마지막 순차열의첫 원소의 반복자
        cout << "iter : " << *iter << endl;
        cout << "iter - 1 : " << *(iter - 1) << endl;
        cout << "iter + 1 : " << *(iter + 1) << endl;
    }

// find_end() 알고리즘 조건자 버전
    vector<int> v3;
    v3.push_back(10);
    v3.push_back(15);
    v3.push_back(20);
    v3.push_back(40);
    v3.push_back(50);
    v3.push_back(60);
    v3.push_back(10);
    v3.push_back(11);
    v3.push_back(12);
    v3.push_back(80);

    vector<int> v4;
    v4.push_back(10);
    v4.push_back(15);
    v4.push_back(25);

    iter = find_end(v3.begin(), v3.end(), v4.begin(), v4.end(), Pred);
    if(iter != v3.end())
    {
        // 일치하는 마지막 순차열의 첫 원소의 반복자 iter
        cout << "iter : " << *iter << endl;
        cout << "iter - 1 :  " << *(iter - 1) << endl;
        cout << "iter + 1 :  " << *(iter + 1) << endl;
    }
    return 0;
}