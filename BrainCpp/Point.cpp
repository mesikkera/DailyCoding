#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(const Point& pt)
{
    x = pt.x;
    y = pt.y;
}

Point::Point(COOR_T initialX, COOR_T initialY)
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