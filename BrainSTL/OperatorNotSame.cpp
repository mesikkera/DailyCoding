#include <iostream>
using namespace std;

class Point 
{
    int x;
    int y;

public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
    void Print() const { cout << x << ',' << y << endl; }

    bool operator==(const Point& arg) const 
    {
        
    }
};