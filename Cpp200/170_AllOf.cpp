#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> data1 = {1, 3, 5, 7};
    vector<string> data2 = {"ab", "cd", "ef"};

    // all_of(): 컨테이너를 순회하며 모든 데이터가 특정 조건게 맞는지 확인하는 함수
    // 3개의 인자: 1) 컨테이너의 순회 시작 위치, 
    //             2) 컨테이너의 마지막 위치,
    //             3) 사용자 정의 조건
    if (all_of(data1.begin(), data1.end(), [](int i) { return i % 2;}))
        cout << "data1 : 모두 홀수입니다." << endl;

    if(all_of(data1.begin(), data1.end(), [](int i) { return i < 10; }))
        cout << "data1: 모두 10보다 작습니다." << endl;

    if(all_of(data2.begin(), data2.end(), [](string i) { return i.length() < 4 ? true : false; }))
        cout << "data2: 모두 길이가 4 이하입니다." << endl;

    if(all_of(data2.begin(), data2.end(), [](string i) { return i.find('A');}))
        cout << "data2: 모두 문자 A를 포함하지 않습니다." << endl;
    
    return 0;
}