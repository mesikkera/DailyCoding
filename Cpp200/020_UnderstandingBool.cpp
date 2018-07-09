#include <iostream>

using namespace std;

int main()
{
    int x = 10;
    int y = 6;

    bool is_true = false;

    if( x > y )
    {
        is_true = true;
    }
    else
    {
        is_true = false;
    }

    if (is_true == true)
    {
        cout << "x is bigger than y" << endl;
    }
    else
    {
        cout << "x is smaller than y" << endl;
    }

    return 0;
}