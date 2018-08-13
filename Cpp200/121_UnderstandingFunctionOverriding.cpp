#include <iostream>

using namespace std;

class Base 
{
public:
    void Display()
    {
        cout << "Ronaldo's team is Juventue." << endl;
    }
};

class Derived : Base 
{
public:
    void Display()
    {
        cout << "Ronaldo's back number is 7" << endl;
    }
};

int main()
{
    Derived child;
    child.Display();

    return 0;
}