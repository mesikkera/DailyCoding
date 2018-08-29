#include <iostream>
using namespace std;

class Point
{
    int x; 
    int y;

public:
    Point(int _x = 0, int _y = 0):x(_x), y(_y) {    }
    int GetX() const    // const 함수 
    {
        return x;
    }

    int GetY() const    // const 함수
    {
        return y;
    }

    void SetX(int _x)   // 비 const 함수 : 멤버 변경
    {
        x = _x;
    }

    void SetY(int _y)   // 비 const 함수 : 멤버 변경
    {
        y = _y;
    }

    void Print() const  // const 함수
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    const Point p1(0, 0);       // const 객체 : 모든 멤버 변경 불가
    Point p2(2, 3);             // 비 const 객체

    p1.Print();
    p2.Print();

    cout << "p1 : " << p1.GetX() << ", " << p1.GetY() << endl;
    cout << "p2 : " << p2.GetX() << ", " << p2.GetY() << endl;

    // p1.SetX(5);      const 객체는 const 멤버 함수만 호출 가능
    // p1.SetY(5);      const 객체는 const 멤버 함수만 호출 가능
    p2.SetX(5);
    p2.SetY(5);

    return 0;
}