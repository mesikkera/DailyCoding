#include "Point.h"

int main()
{
    // 객체 생성
    Point pt(100, 100);             // pt의 생성자 호출

    // 객체 포인터 정의
    Point* p = nullptr;

    // 객체 동적 생성
    p = new Point(50, 50);          // 동적으로 생성한 객체의 생성자 호출

    pt.Print();
    p->Print();

    // 동적 생성 객체 해제 
    delete p;                       // 동적으로 생성한 객체의 소멸자가 호출
    p = nullptr;

    return 0;
}                                   // 함수가 끝나면서 pt의 소멸자가 호출