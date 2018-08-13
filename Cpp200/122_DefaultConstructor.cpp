#include <iostream>

using namespace std;

int GetOne() { return 1; }

int Plus(int x, int y = GetOne(), int z = 1)
{
    return x + y + z;
}

int main()
{
    int number1 = Plus(1);
    int number2 = Plus(1, 2);
    int number3 = Plus(1, 2, 3);

    cout << "Result: " << number1 << ", " << number2 << ", " << number3 << endl;

    return 0;
}