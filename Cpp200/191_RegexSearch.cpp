#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    string str = "Wang Geon, a descendant of Go-gu-ryeo nobility, deemed the nation as the successor of Go-guryeo";

    smatch match_info;
    
    regex re(" Go-([^ ]*)");

    while (regex_search(str, match_info, re))
    {
        cout << match_info.str() << " " << endl;

        str = match_info.suffix().str();
    }

    return 0;
}