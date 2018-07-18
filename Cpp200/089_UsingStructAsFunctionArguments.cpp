#include <iostream>
#include <string>

using namespace std;

struct MyFriends
{
    string name;
    string job;
    string birthday;
} myfriends;

void Print(MyFriends *who)
{
    cout << "myfriends.name = " << who -> name << endl;
    cout << "myfriends.job = " << who -> job << endl;
    cout << "myfriends.birthday = " << who -> birthday << endl;
}

int main()
{
    myfriends.name = "David Beckham";
    myfriends.job = "Soccer Player";
    myfriends.birthday = "1975.01.01";

    Print(&myfriends);

    return 0;
}