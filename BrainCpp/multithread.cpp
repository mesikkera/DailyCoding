#include <string>
#include <iostream>
#include <thread> //쓰레드를 위한 헤더파일

using namespace std;

// 쓰레드가 실행해야 할 함수를 설정해주세요
void task1(string msg)
{
    cout << "task1 says: " << msg;
}

int main()
{
    // 새 쓰레드를 만들어 실행합니다. 현재 쓰레드가 block되지 않습니다.
    thread t1(task1, "Hello");

    // main이가 새로 만든 쓰레드가 일을 마칠 때까지 기다리게 만듭니다.
    t1.join();
}
