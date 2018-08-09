#include "Point.h"

int main()
{
    // 초기화용 객체
    Point pt(50, 50);

    // 동적으로 객체를 생성
    Point* p1 = new Point();
    Point* p2 = new Point(100, 100);
    Point* p3 = new Point(pt);

    // 객체들의 내용 출력
    p1 -> Print();
    p2 -> Print();
    p3 -> Print();

    // 동적으로 생성한 객체 정리
    delete p1;
    delete p2;
    delete p3;
    p1 = p2 = p3 = 0;

    return 0;
}