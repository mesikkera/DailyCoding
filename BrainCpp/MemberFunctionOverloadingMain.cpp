#include "MemberFunctionOverloading.h"

int main()
{
    // 객체 생성
    Point pt( 50, 50 );
    Point delta( 100, 100 );

    // 점을 x축으로 10, y축으로 -10 이동
    pt.Offset(10, -10);

    // 현재 3점의 위치 출력
    pt.Print();

    // 점을 범위 밖으로 이동(안정성 테스트)
    pt.Offset(delta);

    // 현재 점의 위치 출력
    pt.Print();

    return 0;
}