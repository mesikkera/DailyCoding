#include <iostream>
using namespace std;
void Client();

// Server
void PrintHello()
{
    cout << "Hello!" << endl;
    Client();   // 서버에서 클라이언트 코드 호출
}

// Client
void Client()
{
    cout << "I'm Client!" << endl;
}

int main()
{
    PrintHello();   // 서버 코드 호출

    return 0;
}