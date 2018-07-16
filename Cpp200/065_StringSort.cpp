#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string sort_str1 = "republic of korea";
    string sort_str2 = "AaBbCcDdEe";

    sort(sort_str1.begin(), sort_str1.end());
    sort(sort_str2.begin(), sort_str2.end());

    cout << "Lower case sorting: " << sort_str1 << endl;
    cout << "Lower and Upper case sorting: " << sort_str2 << endl;

    return 0;
}