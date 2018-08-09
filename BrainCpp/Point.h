#ifndef POINT_H
#define POINT_H

// Point 클래스 정의
class Point 
{
public:
    // 열거체 정의
    enum { MIN_X = 0, MAX_X = 100, MIN_Y = 0, MAX_Y = 100};

    // 멤버 함수
    void Print();
    
    // 생성자들
    Point();
    Point(int initialX, int initialY);
    Point(const Point& pt);

    // 접근자
    void SetX(int value)
    {
        if (value < MIN_X)          x = 0;
        else if (value > MAX_X)   x = 100;
        else                    x = value;
    }

    void SetY(int value)
    {
        if (value < MIN_Y)          y = 0;
        else if (value > MAX_Y)   y = 100;
        else                    y = value;
    }

    int GetX() { return x; }
    int GetY() { return y; }

private:
    // 멤버 변수
    int x, y;
};

#endif