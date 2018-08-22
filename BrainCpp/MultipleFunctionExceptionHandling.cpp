#include <iostream>
using namespace std;

void A();
void B();
void C();

int main()
{
    try
    {
        A();
    }
    catch(int ex)
    {
        cout << "Exception = " << ex << endl;
    }

    return 0;
}

void A()
{   
    cout << "A() Start!" << endl;
    B();
    cout << "A() End!" << endl;
}

void B()
{
    cout << "B() Start!" << endl;
    C();
    cout << "B() End!" << endl;
}

void C()
{
    cout << "C() Start!" << endl;
    throw 337;
    cout << "C() End!" << endl;
}