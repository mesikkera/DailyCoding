#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence = "I hate coding.";
    cout << sentence << endl;

    // erase 함수: 문자열 일부 제거
    // erase(arg1, arg2)
    // arg1 : 제거할 영역의 시작 인덱스
    // arg2 : 제거할 문자의 개수
    sentence.erase(0, 7);
    cout << "I like " << sentence << endl;

    return 0;
}