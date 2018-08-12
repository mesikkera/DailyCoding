#include "Point.h"

int main()
{
    Point arr[3] = { Point(100, 100), Point(50, 100), Point(10, 10)};

    for (int i = 0; i < 3; ++i)
        arr[i].Print();

    return 0;
}