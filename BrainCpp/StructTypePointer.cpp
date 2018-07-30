#include <iostream>
using namespace std;

struct Rectangle
{
    int x, y;
    int width, height;
};

int main()
{
    Rectangle rc = {100, 100, 50, 50};

    Rectangle* p = &rc;

    // 구조체 멤버 접근
    // *p.x의 경우 우선순위로 인해 p.x가 먼저 해석
    // 따라서 (*p).x라고 해야 *p가 먼저 해석된다.
    // *p는 p가 가리키는 것, 즉 구조체 rc를 의미
    (*p).x = 200;
    p->y = 200;

    // 구조체 출력
    cout << "rc = ( " << rc.x << ", " << rc.y << ", " << rc.width << ", " << rc.height << " ) " << endl; 
    cout << "rc = ( " << (*p).x << ", " << (*p).y << ", " << (*p).width << ", " << (*p).height << " ) " << endl;
    cout << "rc = ( " << p->x << ", " << p->y << ", " << p->width << ", " << p->height << " ) " << endl;
    return 0;
}