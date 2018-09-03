#include <iostream>
using namespace std;

// 정수 출력
void Print(int a, int b)
{
    cout << a << ", " << b << endl;
}

void Print(double a, double b)
{
    cout << a << ", " << b << endl;
}

void Print(const char* a, const char* b)
{
    cout << a << ", " << b << endl;
}

int main()
{
    Print(10, 20);          // 정수 출력
    Print(0.123, 1.123);    // 실수 출력
    Print("ABC", "abcde");  // 문자열 출력
    return 0;
}

