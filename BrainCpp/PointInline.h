#ifndef POINTINLINE_H
#define POINTINLINE_H

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
    void SetX(int value);
    void SetY(int value);
    int GetX() { return x; }
    int GetY() { return y; }

private:
    int x, y;
};

// 인라인 함수는 반드시 헤더파일에 있어야 한다. 
inline void Point::SetX(int value)
{
    if (value < 0)
        x = 0;
    else if (value > 100)
        x = 100;
    else 
        x = value;
}

// 인라인 함수는 반드시 헤더파일에 있어야 한다.
inline void Point::SetY(int value)
{
    if (value < 0)
        y = 0;
    else if (value > 100)
        y = 100;
    else
        y = value;
}

#endif