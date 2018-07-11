#include <iostream>

using namespace std;

int main()
{
    int number1 = 65;
    double number2 = 23.4;

    int number3 = int(number2);
    double number4 = double(number1 / number2);

    char ch = char(number1);

    cout << "number1 : " << number1 << endl;
    cout << "number2 : " << number2 << endl;
    cout << "number3 : " << number3 << endl;
    cout << "number4 : " << number4 << endl;
    cout << "ch : " << ch << endl;

    return 0;
}
