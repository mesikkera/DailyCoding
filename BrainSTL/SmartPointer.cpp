#include <iostream>
using namespace std;

class Point 
{
    int x;
    int y;
public:
    Point (int _x = 0, int _y = 0):x(_x), y(_y) { }
    void Print() const { cout << x << ", " << y << endl; }
};

class PointPtr 
{
    Point *ptr;
public:
    PointPtr(Pint *p):ptr(P) { } 
    ~PointPtr()
    {
        delete ptr;
    }
};

int main()
{
    PointPtr p1 = new Point(2, 3);      // 메모리 할당
    PointPtr p2 = new Point(5, 5);      // 메모리 할당

    return 0;
}