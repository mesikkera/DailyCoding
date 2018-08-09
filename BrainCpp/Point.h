#ifndef POINT_H
#define POINT_H

// Point 클래스 정의
class Point 
{
public:
    // 멤버 함수
    void Print();
    
    // 생성자들
    Point();
    Point(int initialX, int initialY);
    Point(const Point& pt);

    // 접근자
    void SetX(int value)
    {
        if (value < 0)          x = 0;
        else if (value > 100)   x = 100;
        else                    x = value;
    }

    void SetY(int value)
    {
        if (value < 0)          y = 0;
        else if (value > 100)   y = 100;
        else                    y = value;
    }

    int GetX() { return x; }
    int GetY() { return y; }

private:
    // 멤버 변수
    int x, y;
};

#endif