#include <iostream>
using namespace std;

typedef void (*SYSTEM_FUNC)();

void ForWindows9x();
void ForWindowsNT();
bool IsWindows9x();
void ImportantFunc(SYSTEM_FUNC pfnSyst);

int main()
{
    // 함수 포인터 변수 정의
    SYSTEM_FUNC pfn;

    // 시스템 버전에 따라서 알맞은 함수를
    // 가리키게 만든다.
    if (IsWindows9x())
        pfn = &ForWindows9x;
    else
        pfn = &ForWindowsNT;

    // 아주 중요한 함수 호출
    ImportantFunc(pfn);

    return 0;
}

// Windows 95/98/Me 용 함수
void ForWindows9x()
{
    cout << "Windows 9x 용 함수가 호출됨"<< endl;
}

// Windows NT/2000/XP용 함수
void ForWindowsNT()
{
    cout << "Windows NT/2000/XP 용 함수가 호출됨" << endl;
}  

// 현재 실행되는 환경을 windows 9x인지 반환하는 함수
bool IsWindows9x()
{
    // 임의로 false 반환
    return false;
}

void ImportantFunc(SYSTEM_FUNC pfnSyst)
{
    (*pfnSyst)();

    // 중간 생략

    // 재호출
    (*pfnSyst)();
}