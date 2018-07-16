#include <iostream>
#include <string>

using namespace std;

int main()
{
    int number1 = 10;
    double number2 = 67.8;

    string no_str1 = to_string(number1);
    string no_str2 = to_string(number2);

    cout << "number1 : " << number1 << endl;
    cout << "number2 : " << number2 << endl;

    return 0;
}