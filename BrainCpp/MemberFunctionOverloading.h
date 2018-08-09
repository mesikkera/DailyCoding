#ifndef MEMBERFUNCTIONOVERLOADING_H
#define MEMBERFUNCTIONOVERLOADING_H

// Point 클래스 정의
class Point 
{
public:
    // 멤버 함수
    void Print() const;
    void Offset(int x_delta, int y_delta);
    void Offset(const Point& pt);

    // 생성자들
    Point();
    Point(int initialX, int initialY);
    Point(const Point& pt);

    // 접근자
    void SetX(int value);
    void SetY(int value);
    int GetX() const { return x; }
    int GetY() const { return y; }

private:
    // 멤버 변수
    int x, y;
};

inline void Point::SetX(int value)
{
    if (value < 0)           x = 0;
    else if (value > 100)    x = 100;
    else                     x = value;
}

inline void Point::SetY(int value)
{
    if (value < 0)           y = 0;
    else if (value > 100)    y = 100;
    else                     y = value;
}

#endif