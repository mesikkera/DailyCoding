#include <iostream>
using namespace std;

class Point 
{
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0):x(_x), y(_y) {}
    void Print() const { cout << x << ", " << y << endl; }
    // void operator++ ()
    // {
    //     // 전위 ++ 연산자
    // }   
    // void operator++(int)
    // {
    //     // 후위 ++ 연산자
    // }
    const Point& operator++() // 전위++
    {
        ++x;
        ++y;
        return *this;
    }

    const Point operator++(int) // 후위++
    {
        Point pt(x, y);
        x++;
        y++;
        return pt;
    }
};

int main()
{
    Point p1(2, 3), p2(2, 3);

    // ++p1; // p1.operator++(); 

    // p2++; // p2.oerator++(0);

    Point result;

    result = ++p1;      // p1.operator++();
    p1.Print();
    result.Print();

    result = p2++;      // p2.operator++(0);
    p2.Print();
    result.Print();

    return 0;

    return 0;
}