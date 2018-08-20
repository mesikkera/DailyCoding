#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    // \d: 검색 조건은 숫자
    // + : 앞의 조건을 1번 또는 여러번 반복
    // \d+ : 숫자를 찾는데 한 자리가 아니라 여러자리
    // C++에서 정규표현식은 R"()"형태로 표현, 실제규칙은 () 안에 작성.
    regex re1(R"(\d+)");
    string str1("1234");

    // regex_match(문자열, 규칙): 문자열이 규칙에 부합하면 true 리턴
    bool is_match = regex_match(str1, re1);

    cout << boolalpha;
    cout << "is_match = " << is_match << endl;

    regex re2(R"(\d+)");
    string str2 = "ab 123456 cd ef";

    smatch match_info;
    regex_search(str2, match_info, re2);

    cout << "number : " << match_info.str() << endl;

    return 0;

}