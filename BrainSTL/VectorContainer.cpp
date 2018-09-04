#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // int 타입을 저장하는 컨테이너 V를 생성
    vector<int> v;

    v.push_back(10);        // v에 정수 10 추가
    v.push_back(20);        // v에 정수 20 추가
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for(unsigned int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;       // v[i]는 i번째 index의 정수 

    return 0;
}