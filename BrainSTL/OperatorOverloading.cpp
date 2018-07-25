#include <iostream>
usng namespace std;

class Point 
{
    int x;
    int y;
public: 
    Point(int _x=0, int _y=0):x(_x), y(_y) { }
    void Print() const { cout << x << ", " << y << endl; }
};

class PointPtr 
{
    Point *ptr;
public:
    PointPtr(Point *p):ptr(p) { }

    ~PointPtr()
    {
        delete ptr;
    }

    Point* operator->() const
    {
        return ptr;
    }
};

int main()
{
    // 메모리 할당
    PointPtr p1 = new Point(2, 3);
    POintPtr p2 = new Point(5, 5);

    p1->Print();        // p1.operator->()->Print() 호출
    p2->Print();        // p2.operator->()->Print() 호출
}