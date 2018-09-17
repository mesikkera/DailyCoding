#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/asio.hpp>

using namespace std;

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
    return 0;
}