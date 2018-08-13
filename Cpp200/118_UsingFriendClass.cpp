#include <iostream>
#include <string>

using namespace std;

class GoodTeam;
class BadTeam;

class Info 
{
    friend class GoodTeam;

public:
    Info() {}

private:
    string team;
};

class GoodTeam : public Info 
{
public:
    GoodTeam()
    {
        team = "Jeju United";
    }
    void Display()
    {
        cout << team << endl;
    }
};

class BadTeam : public Info 
{
public:
    BadTeam() {};
    void Display()
    {
        /*
        118_UsingFriendClass.cpp: In member function ‘void BadTeam::Display()’:
        118_UsingFriendClass.cpp:39:17: error: ‘std::__cxx11::string Info::team’ is private within this context
                cout << team << endl; // 에러
                        ^~~~
        118_UsingFriendClass.cpp:17:12: note: declared private here
                string team;
                       ^~~~
        */
        cout << team << endl; // 에러
    }
};

int main()
{
    GoodTeam team1;
    team1.Display();

    BadTeam team2;
    team2.Display();

    return 0;
}