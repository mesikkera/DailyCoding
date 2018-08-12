#include <iostream>
#include <string>

using namespace std;

class TmpClass 
{
public:
    TmpClass() : number1(10), number2(20), name("ronaldo : Juventus"){}

    void Print()
    {
        cout << number1 << ", " << number2 << ", " << number3 << ", " << name << endl;
    }

private:
    int number1 = 1;
    const int number2 = 2;
    static const int number3 = 7;
    string name = "messi : Barcelona";
};

int main()
{
    TmpClass tc;
    tc.Print();

    return 0;
}