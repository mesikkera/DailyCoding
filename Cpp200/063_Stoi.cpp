#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1 = "10";
    string str2 = "2.456";
    string str3 = "456 string";

    int num1 = stoi(str1);
    int num2 = stoi(str2);
    int num3 = stoi(str3);

    cout << num1 << ", " << num2 << ", " << num3 << endl;

    return 0;
}