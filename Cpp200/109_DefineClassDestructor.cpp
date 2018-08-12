#include <iostream>

using namespace std;

class TempClass
{
public:
    // Constructor
    TempClass()
    {
        cout << "Call Constructor!" << endl;
    }

    // Destructor
    ~TempClass()
    {
        cout << "Call Destructor!" << endl;
    }
};

int main()
{
    TempClass* temp_class = new TempClass();

    delete temp_class;
    temp_class = nullptr;

    return 0;
}