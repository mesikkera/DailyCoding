#include <iostream>
using namespace std;

int main()
{
    // 상수형 변수는 일반 변수와 달리 한 번 값이 
    // 할당되면 프로그램이 종료될 때까지 값이 변할 수 없다.
    const int GREATE_VICTORY_SALSU = 612;
    const int GREATE_VICTORY_GWIJU = 1019;

    cout << "고구려 살수대첩 연도: " << GREATE_VICTORY_SALSU << "년" << endl;
    cout << "고려 귀주대첩 연도: " << GREATE_VICTORY_GWIJU << "년" << endl;

    return 0;
}