#include <iostream>
using namespace std;

class Point 
{
    int x;
    int y;
public:
    explicit Pont(int _x=0, int _y=0):x(_x), y(_y) { } 
    void Print() const { cout << x << ", " << y << endl; }
    operator int() const 
    {
        return x;
    }
};

int main()
{
    int n = 10;

    Point pt(2, 3);
    n = pt;     // pt.operator int() 암시적 호출
    cout << n << endl;

    return 0;
}