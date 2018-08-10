#ifndef RECT_H
#define RECT_H

// #include "Point.h"
#include "PointInline.h"

class Rect 
{
public:
    // 생성자
    Rect();

    // 각 점의 값 지정/얻기: 접근자
    void SetTopLeft(const Point& topLeft);
    void SetBottomRight(const Point& bottomRight);
    void SetRect(int left, int top, int right, int bottom);
    void SetTopLeft() const;
    Point GetTopLeft() const;
    Point GetBottomRight() const;
    void GetRect(int& left, int& top, int& right, int& botom);

    // 넓이, 높이 계산
    int GetWidth() const;
    int GetHeight() const;

    // 내용 출력
    void Print() const;

protected:
    // 2개의 포인트 객체를 멤버 변수로 가지고 있다.
    Point _topLeft;
    Point _bottomRight;
};

#endif