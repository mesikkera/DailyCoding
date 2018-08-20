#include <iostream>
#include <vector>
#include <regex>
#include <string>

using namespace std;

int main()
{
    regex re(R"(\d+)");
    const string str = "12 34ab 56 cd78__ !9 10 == 11";

    vector<string> result;
    auto start = str.begin();
    auto end = str.end();

    smatch match_info;

    while (regex_search(start, end, match_info, re))
    {
        result.push_back(match_info.str());
        start = match_info[0].second;
    }

    for (auto i : result)
        cout << i << ", ";

    return 0;
}