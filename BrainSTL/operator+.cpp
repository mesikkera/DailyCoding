#include <iostream>
using namespace std;

class Point 
{
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0):x(_x), y(_y) {}
    void Print() const { cout << x << ", " << y << endl;}
    // 01. 함수 호출 여부 확인
    // void operator+(Point arg)
    // {
    //     cout << "operator+ Function call" << endl;
    // }

    // 02. 연산자 오버로딩 테스트 구현
    // void operator+(const Point& arg)
    // {
    //     Point pt;
    //     pt.x = this->x + arg.x;
    //     pt.y = this->y + arg.y;
    //     cout << "p1 + p2 = " << "(" << pt.x << ", " << pt.y << ")" << endl;
    // }

    // 03. 연산자 오버로딩 함수 완성
    const Point operator+(const Point& arg) const
    {
        Point pt;
        pt.x = this->x + arg.x;
        pt.y = this->y + arg.y;

        return pt;
    }
};

int main()
{
    Point p1(2, 3), p2(5, 5);
    Point p3;

    // p1 + p2;    // => p1.operator+(p2)
    p3 = p1 + p2;           // 컴파일러가 p1.operator+(p2)로 해석해서 호출한다.
    p3.Print();
    p3 = p1.operator+(p2);  // 직접 호출
    p3.Print();

    return 0;
}