#include <iostream>
using namespace std;

class Point 
{
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0):x(_x), y(_y) { }
    void Print() const { cout << x << ", " << y << endl; }
    bool operator==(const Point& arg) const 
    {
        return x == arg.x && y == arg.y ? true : false;
    }
};

int main()
{
    Point p1(2, 3), p2(5, 5), p3(2, 3);

    if(p1== p2)
        cout << "p1 == p2" << endl;
    if(p1== p3)
        cout << "p1 == p3" << endl;

    return 0;
}