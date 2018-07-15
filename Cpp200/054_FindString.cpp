#include <iostream>
#include <string>

using namespace std;

int main()
{
    string test_string = "South Korea";

    int rtn = test_string.find("Korea");

    if (rtn > 0)
        cout << "Find Strnig! Location is : " << rtn << endl;
    else
        cout << "Do not find String!" << endl;

    return 0;
}