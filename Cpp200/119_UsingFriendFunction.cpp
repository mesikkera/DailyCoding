#include <iostream>
#include <string>

using namespace std;

class Ronaldo
{
public:
    friend void GetTeam(Ronaldo ronaldo)
    {
        cout << "Ronaldo's New Team: " << ronaldo.team_ << endl;
    }

    void SetTeam(string team)
    {
        team_ = team;
    }

private:
    string team_;
};

int main()
{
    Ronaldo ronaldo;
    ronaldo.SetTeam("Juventus");

    GetTeam(ronaldo);

    return 0;
}