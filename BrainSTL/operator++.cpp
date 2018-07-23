#include <iostream>
using namespace std;

class Point 
{
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0):x(_x), y(_y) {}
    void Print() const { cout << x << ", " << y << endl; }
    void operator++ ()
    {
        // 전위 ++ 연산자
    }   
    void operator++(int)
    {
        // 후위 ++ 연산자
    }
};

int main()
{
    Point p1(2, 3), p2(2, 3);

    ++p1; // p1.operator++(); 

    p2++; // p2.oerator++(0);

    return 0;
}