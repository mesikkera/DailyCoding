#include <iostream>
using namespace std;

int main()
{
    // 실험에 사용할 변수를 정의
    int target = 20;

    // 레퍼런스 변수 정의
    int& ref = target;

    // 정보 출력
    cout << "ref = " << ref << endl;
    cout << "target = " << target << endl;
    cout << "&ref = " << &ref << endl;
    cout << "&target = " << &target << endl;

    // ref값 변경
    ref = 100;

    // 정보 출력
    cout << "ref = " << ref << endl;
    cout << "target = " << target << endl;

    return 0;
}