#ifndef POINT_H
#define POINT_H

// Point 클래스 정의
class Point 
{
public:
    // 열거체 정의
    enum { MIN_X = 0, MAX_X = 100, MIN_Y = 0, MAX_Y = 100};

    // static const 멤버 변수 사용
    // static const MIN_X = 0;
    // static const MAX_X = 100;
    // static const MIN_Y = 0;
    // static const MAX_Y = 100;

    // typedef도 클래스 내에서 통용되는 타입 재정의 가능
    typedef int COOR_T;                 // 좌표의 타입(int타입을 COOR_T로 재정의)

    // 멤버 함수
    void Print();
    
    // 생성자들
    Point();
    Point(COOR_T initialX, COOR_T initialY);
    Point(const Point& pt);

    // 접근자
    void SetX(COOR_T value)
    {
        if (value < MIN_X)          x = 0;
        else if (value > MAX_X)   x = 100;
        else                    x = value;
    }

    void SetY(COOR_T value)
    {
        if (value < MIN_Y)          y = 0;
        else if (value > MAX_Y)   y = 100;
        else                    y = value;
    }

    int GetX() { return x; }
    int GetY() { return y; }

private:
    // 멤버 변수
    COOR_T x, y;
};

#endif