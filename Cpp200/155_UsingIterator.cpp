#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> data({1, 2, 3});


    // 반복자
    // * : 현재 위치
    // ++ : 다음 위치
    // -- : 이전 위치
    // ==, != : 같은 위치여부 비교
    // = : 반복자 설정
    for(vector<int>::iterator iter = data.begin(); iter != data.end(); ++iter)
    {
        cout << *iter << ", ";
    }

    for (auto iter = data.begin(); iter != data.end(); ++iter)
    {
        cout << *iter << ", ";
    }

    for(auto iter = data.rbegin(); iter != data.rend(); ++iter)
    {
        cout << *iter << ", ";
    }

    // 벡터 내부 데이터 전체 삭제
    data.clear();

    return 0;
}