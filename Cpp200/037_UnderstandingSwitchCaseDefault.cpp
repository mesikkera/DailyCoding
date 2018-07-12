#include <iostream>

using namespace std;

int main()
{
    int number = 3;

    switch (number)
    {
        case 1:
            cout << "number is 1." << endl;
            break;
        case 2:
            cout << "number is 2." << endl;
            break;
        case 3:
            cout << "number is 3." << endl;
            break;
        default:
            cout << "number is unknown." << endl;
            break;
    }
    return 0;
}