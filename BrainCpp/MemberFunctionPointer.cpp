#include "Point.h"

// void XX() 형태의 함수에 대한 포인터
// 멤버가 아닌 함수에 대한 포인터
typedef void (*FP1)(int);

// void Point::XX() 형태의 멤버 함수에 대한 포인터
// Point 클래스의 멤버 함수에 대한 포인터
typedef void (Point::*FP2)(int);

// Point 클래스의 멤버 함수에 대한 포인터: Point::Print()
typedef void (Point::*FP3)();

int main()
{
    // 객체 생성
    Point pt(50, 50);

    // FP1, FP2를 사용해서 SetX() 함수를 가리킨다.
    // FP1 fp1 = &Point::SetX;              // 오류
    FP2 fp2 = &Point::SetX;                 // 성공: SetX() 함수의 주소를 fp2에 대입한다.
    FP3 fp3 = &Point::Print;

    // 함수 포인터를 사용해서 함수 호출
    (pt.*fp2)(100);

    // 내용 출력
    pt.Print();
    (pt.*fp3)();
    
    return 0;
}