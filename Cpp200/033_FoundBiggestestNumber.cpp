#include <iostream>
#include <string>

using namespace std;

int main()
{
    int number1 = 100;
    int number2 = 200;
    int number3 = 300;

    if (number1 > number2 && number1 > number3)
        cout << "Biggest Number is " << number1 << endl;
    else if (number2 > number1 && number2 > number3)
        cout << "Biggest Number is " << number2 << endl;
    else if (number3 > number1 && number3 > number2)
        cout << "Biggest Number is " << number3 << endl;
    else
        cout << "Not Found!" << endl;

    return 0;        
}