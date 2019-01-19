#include <iostream>
using namespace std;

struct FuncObject
{
public:
    void operator() (int arg) const 
    {
        cout << "integer: " << arg << endl;
    }

    void operator() (int arg1, int arg2) const 
    {
        cout << "integer: " << arg1 << ", " << arg2 << endl;
    }
}