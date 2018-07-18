#include <iostream>
#include <string>

using namespace std;

struct Friends
{
    string name;
    string job;
    string birthday = "Unknown";
} MyFriends[2];

int main()
{
    Friends daniel;
    daniel.name = "daniel craig";
    daniel.job = "actor";
    daniel.birthday = "1960.01.01";

    MyFriends[0].name = "Sam Bridge";
    MyFriends[0].job = "Programmer";
    MyFriends[1].name = "Sandara Park";
    MyFriends[1].job = "Singer";

    cout << "== My Friends ==" << endl;
    cout << daniel.name << endl;
    cout << daniel.job << endl;
    cout << daniel.birthday << endl << endl;
    cout << MyFriends[0].name << endl;
    cout << MyFriends[0].job << endl;
    cout << MyFriends[0].birthday << endl << endl;
    cout << MyFriends[1].name << endl;
    cout << MyFriends[1].job << endl;
    cout << MyFriends[1].birthday << endl;

    return 0;
}