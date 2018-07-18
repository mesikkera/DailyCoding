#include <iostream>
#include <string>

using namespace std;

struct Info 
{
    string country;

    struct who 
    {
        string name;
        string skill;
    } who;
};

int main()
{
    Info ronaldo = { "portugal", {"Cristiano Ronaldo", "FreeKick Master"} };
    Info messi = {"Argentina", {"Lionel Messi", "Pass Master"} };

    cout << ronaldo.country << ", " << ronaldo.who.name << ", " << ronaldo.who.skill << endl;
    cout << messi.country << ", " << messi.who.name << ", " << messi.who.skill << endl;

    return 0;
}