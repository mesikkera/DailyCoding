#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    // \: or. 또는 이란 의미로 여러 조건을 사용할 때 구분자로 사용
    // \D : 숫자를 제외한 문자만을 대상
    // \s : 공백 문자만을 대상
    regex re1(R"(l|i|k|e)");            // 문자 l, i, k, e를 찾는 정규표현식
    regex re2(R"(\D)");                 // 숫자를 제외한 문자를 찾는 정규표현식
    regex re3(R"(\s)");                 // 공백 문자를 찾는 정규표현식
    string str = "i like coding";

    // regex_replace(대상문자열, 정규표현식, 변경할 형식)
    // $&: 찾아낸 문자 또는 문자열을 불러온다.
    string result1 = regex_replace(str, re1, "[$&]");
    string result2 = regex_replace(str, re1, "*");
    string result3 = regex_replace(str, re2, "_$&_");
    string result4 = regex_replace(str, re3, "(space)");

    cout << "result1 : " << result1 << endl;
    cout << "result2 : " << result2 << endl;
    cout << "result3 : " << result3 << endl;
    cout << "result4 : " << result4 << endl;

    return 0;
}