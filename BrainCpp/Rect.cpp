#include "Rect.h"
#include <iostream>
using namespace std;

Rect::Rect()
{
}

void Rect::SetTopLeft(const Point& bottomRight)
{
    _bottomRight = bottomRight;
}

void Rect::SetRect(int left, int top, int right, int bottom)
{
    _topLeft.SetX(left);
    _topLeft.SetY(top);
    _bottomRight.SetX(right);
    _bottomRight.SetY(bottom);
}

Point Rect::GetTopLeft() const 
{
    return _topLeft;
}

Point Rect::GetBottomRight() const 
{
    return _bottomRight;
}

void Rect::GetRect(int& left, int& top, int& right, int& bottom)
{
    left = _topLeft.GetX();
    top = _topLeft.GetY();
    right = _bottomRight.GetX();
    bottom = _bottomRight.GetY();
}

// 넓이 계산
int Rect::GetWidth() const
{
}

// 높이 계산
int Rect::GetHeight() const 
{
 
}

// 내용 출력
void Rect::Print() const 
{
   
}


