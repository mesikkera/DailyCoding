#include <iostream>
using namespace std;

void Print(int n)
{
    cout << "정수 : " << n << endl;
}

int main()
{
    // void Print(int)의 함수 포인터 선언
    void (*pf)(int);
    // 함수의 이름은 함수의 시작 주소
    pf = Print;

    Print(10);      // 01. 함수 호출
    pf(10);         // 02. 포인터를 이용한 함수 호출, 첫 번째 방법
    (*pf)(10);      // 03. 포인터를 이용한 함수 호출, 두 번째 방법

    cout << endl;
    cout << Print << endl;
    cout << pf << endl;
    cout << *pf << endl;

    return 0;


}