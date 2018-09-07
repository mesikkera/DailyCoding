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

    // 순차열 [v.begin(), v.end()) 로 v2를 초기화
    vector<int> v2(v.begin(), v.end());

    vector<int>::iterator iter;
    for(iter = v2.begin(); iter != v2.end(); ++iter)
        cout << *iter << " ";       // v2 출력
    cout << endl;

    vector<int> v3;
    // v3에 순차열 [v.begin(), v.end())을 할당
    v3.assign(v.begin(), v.end());
    for(iter = v3.begin(); iter != v3.end(); ++iter)
        cout << *iter << " ";       // v3 출력
    cout << endl;

    return 0;
}