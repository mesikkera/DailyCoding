#include <iostream>
#include <string>

using namespace std;

int Plus(int arg1, int arg2)
{
    return arg1 + arg2;
}

double Plus(double arg1, double arg2, double arg3)
{
    return arg1 + arg2 + arg3;
}

int main()
{
    int number1 = Plus(2, 4);
}