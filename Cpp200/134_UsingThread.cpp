#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void Pause(int sec)
{
    this_thread::sleep_for(chrono::seconds(sec));
};

int main()
{
    thread sleep1(Pause, 3);
    thread sleep2(Pause, 4);
    thread sleep3(Pause, 5);

    sleep1.join();
    cout << "3초 대기" << endl;

    sleep2.join();
    cout << "4초 대기" << endl;

    sleep3.join();
    cout << "5초 대기" << endl;

    return 0;
}