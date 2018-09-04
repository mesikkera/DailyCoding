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

    vector<int>::iterator iter;     // 반복자 생성(아직은 원소를 가리키지 않는다.)
    for(iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << endl;      // 반복자가 가리키는 원소를 역참조
    
    return 0;
}