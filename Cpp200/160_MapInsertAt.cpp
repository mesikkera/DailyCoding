#include <iostream>
#include <map>
#include <string>

using namespace std;

void Print(const map<int, string> &data)
{
    cout << "== Print == " << endl;

    for (auto iter = data.begin(); iter != data.end(); ++iter)
    {
        cout << iter -> first << " : " << iter -> second << ", ";
    }

    cout << endl;
}

int main()
{
    // map 정의
    // map은 key와 value를 한 쌍으로 이용.
    // 데이터 삽입, 수정, 삭제는 모두 키를 이용.
    // key는 중복 불가, value는 중복 가능
    map<int, string> data;
    data.insert({0, "호날두"});
    data.insert({1, "메시"});

    Print(data);

    auto ret = data.insert({1, "손흥민"});
    if (ret.second == true)
        cout << "== Data Insertion Success ==" << endl;
    else 
        cout << "== Data Insertion Fail ==" << endl;
    
    data.at(0) = "음바페";

    Print(data);

    return 0;
}