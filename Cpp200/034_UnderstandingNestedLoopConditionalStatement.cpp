#include <iostream>

using namespace std;

int main()
{
    int number = 7;

    for (int i = 0; i < 10; i++)
    {
        if (i % 3 == 0)
            continue;
        else if (i == number)
            break;
        else
            cout << "i value: " << i << endl;
    }
    return 0;
}