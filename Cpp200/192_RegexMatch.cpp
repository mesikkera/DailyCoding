#include <iostream>
#include <vector>
#include <regex>
#include <string>

using namespace std;

int main()
{
    vector<string> Korea = {
        "Republic of Korea",
        "Republic of korea",
        "republic of Korea",
        "republic of korea",
        "South Korea",
        "South korea",
        "south Korea",
        "south korea",
    };

    // [xy] : 괄호 안의 모든 문자를 찾는다.
    // () : 괄호 안의 내용은 하나의 그룹이 된다.
    // \ : 다음에 오는 메타 문자를 찾는다.
    // \s : 공백 문자를 찾는다.
    // . : 임의의 문자를 나타낸다.
    // * : 앞 문자가 0개 이상 일치하는 문자열 
    regex re("([Rr]epublic)\\s.*");

    smatch match_info;

    for (auto i : Korea)
    {
        if (regex_match(i, match_info, re))
            cout << match_info[0] << endl;
    }

    return 0;
}