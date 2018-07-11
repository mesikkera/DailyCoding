#include <iostream>

using namespace std;

int main()
{
    int number1 = 100;
    int number2 = 6;

    if (number1 < number2)
        cout << "number2 is bigger than number1. " << endl;
    else if (number1 > number2)
        cout << "number1 is bigger than number2. " << endl;
    else
        cout << "number1 and number2 are the same." << endl;

    if (number2 < 7 ) 
    {
        if (number2 > 3)
        {
            if (number2 == 4)
                cout << "number2 is 4. " << endl;
            else if (number2 == 5)
                cout << "number2 is 5." << endl;
            else
                cout << "number2 is 6." << endl;
        }
        else
        {
            if (number2 == 3)
                cout << "number2 is 3. " << endl;
            else if (number2 == 2)
                cout << "number2 is 2. " << endl;
            else
                cout << "number2 is smaller than 1. " << endl;
        }
    }
    return 0;
}