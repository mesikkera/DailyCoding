#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // 2개의 문자열
    char str1[20] = "abcde";
    char str2[] = "fghij";

    // 문자열 결합
    strcat(str1, str2);

    // 결합한 문자열의 비교
    if ( strcmp(str1, "abcdefghij") == 0)
        cout << "str1 and \"abcdefghij\" are identical.\n";

    // 다른 문자열과 비교
    if (strcmp("123456", str1) != 0)
        cout << "\"123456\" and str1 are NOT identical.\n";

    return 0;
}