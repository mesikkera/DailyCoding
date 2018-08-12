#include <iostream>

using namespace std;

static class Calculator
{
public:
    int Plus(const int x, const int y) const 
    {
        return x + y;
    }
} calc;

int main()
{
    cout << "1 + 2 = " << calc.Plus(1, 2) << endl;

    return 0;
}