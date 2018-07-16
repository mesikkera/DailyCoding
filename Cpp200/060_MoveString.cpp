#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str1 = "I like coding";
    // move()
    // 문자열을 복사하지 않고 다른 곳으로 이동
    // 잘라내기 기능과도 같아 기존 변수의 내용은 삭제되고 다른 문자열로 이동.
    string str2 = move(str1);

    cout << "str1 : " << str1 << endl;
    cout << "str2 : " << str2 << endl;

    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = move(v1);

    cout << "v1 size : " << v1.size() << endl;
    cout << "v2 size : " << v2.size() << endl;

    return 0;
}