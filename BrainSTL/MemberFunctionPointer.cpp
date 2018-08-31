#include <iostream>
using namespace std;

class Point 
{
    int x;
    int y;
public:
    explicit Point(int _x = 0, int _y = 0):x(_x), y(_y) { }
    void Print() const { cout << x << ',' << y << endl; }
    void PrintInt(int n) { cout << "Test Integer : " << n << endl; }
};

int main()
{
    Point pt(2, 3);
    Point *p = &pt;

    void (Point::*pf1)() const;             // 멤버 함수 포인터 선언
    pf1 = &Point::Print;

    void (Point::*pf2)(int);                // 멤버 함수 포인터 선언
    pf2 = &Point::PrintInt;

    pt.Print();                             
    pt.PrintInt(10);
    cout << endl;

    // 객체로 멤버 함수 포인터를 이용한 호출
    (pt.*pf1)();
    (pt.*pf2)(10);
    cout << endl;

    // 주소로 멤버 함수 포인터를 이용한 호출
    (p->*pf1)();
    (p->*pf2)(10);

    return 0;
}