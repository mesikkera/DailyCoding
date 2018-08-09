#include "MemberFunctionOverloading.h"
#include <iostream>
using namespace std;

void Point::Offset(int x_delta, int y_delta)
{
    SetX(x + x_delta);
    SetY(y + y_delta);
}

void Point::Offset(const Point& pt)
{
    Offset(pt.x, pt.y);
}

Point::Point(const Point& pt)
{
    x = pt.x;
    y = pt.y;
}

Point::Point(int initialX, int initialY)
{
    SetX(initialX);
    SetY(initialY);
}

Point::Point()
{
    x = 0;
    y = 0;
}

void Point::Print() const 
{
    cout << " ( " << x << " , " << y << " )\n";
}