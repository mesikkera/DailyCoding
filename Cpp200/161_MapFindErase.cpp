#include <iostream>
#include <map>
#include <string>

using namespace std;

// map 내용 출력
void Print(const map<int, string> &data)
{
    cout << "== Print ==" << endl;

    for (auto iter = data.begin(); iter != data.end(); ++iter)
        cout << iter->first << " : " << iter->second << ", ";

    cout << endl;
}

int main()
{
    map<int, string> data;
    data.insert({7, "호날두"});
    data.insert({10, "메시"});
    data.insert({11, "긱스"});

    data[7] = "베컴";

    // 키를 이용하여 값을 찾음.
    auto result = data.find(11);

    if(result != data.end())
        cout << "== Search Success : " << result->first << ", " << result->second << endl;
    else
        cout << "== Search Fail! == " << endl;

    data.erase(10);

    Print(data);

    return 0;
}