#include "Point.h"
#include <iostream>
using namespace std;

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

void Point::Print()
{
    cout << " ( " << x << " , " << y << " ) \n";
}