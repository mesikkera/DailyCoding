#include <bitset>
#include <iostream>
using namespace std;

// 16비트 칼라에서 한 점을 나타내는 구조체
struct Pixel16 
{
    unsigned int blue : 5;
    unsigned int green : 6;
    unsigned int red : 5;
};

// Pixel16과 unsigned short를 멤버로 가진 공용체
union Convert16
{
    Pixel16 pixel;
    unsigned short us;
};

int main()
{
    // 한 점의 색상을 보관하는 변수
    // (임의의 값을 넣어둔다)
    unsigned short color = 0x1234;

    // unsigned short 타입의 값을 Pixel16 구조체 타입인 것처럼
    // 다루기 위해 공용체를 사용한다.
    Convert16 convert;
    convert.us;

    // 결과 출력
    cout << "color = " << bitset<16>(color) << " ( " << color << " )\n";
    cout << "blue = " << bitset<16>(convert.pixel.blue) << " (" << convert.pixel.blue << ")\n";

    return 0;
}