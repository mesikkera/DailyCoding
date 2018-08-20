#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    // \S : 공백 문자가 아닌 것. 숫자, 문자 특수문자 모두 검색 대상에 해당
    // \t : Tab 검색을 합니다.
    regex re1(R"(\S)");
    regex re2(R"(\t)");
    string str = "i\tlike\tcoding";

    //format_first_only: 첫 번째 찾아낸 결과만 수정하고 중단
    string result1 = regex_replace(str, re1, "[$&]", regex_constants::format_first_only);
    string result2 = regex_replace(str, re2, "(Tab)", regex_constants::format_first_only);

    cout << "result1 : " << result1 << endl;
    cout << "result2 : " << result2 << endl;

    return 0;
}