#include <iostream>

using namespace std;

int main()
{
    string string_compare1 = "South Korea";
    string string_compare2 = "North Korea";

    // 문자열 비교: compare()
    // 서로 값이 같다면 0 리턴
    // 서로 값이 다르면 -1 리턴
    if (string_compare1.compare(string_compare2) == 0)
        cout << "Same String!" << endl;
    else
        cout << "Defferent String!" << endl;

    return 0;
}