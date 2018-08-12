#include <iostream>
#include <string>

using namespace std;

class PlayerInfo
{
public:
    PlayerInfo(){};

public:
    void SetValue(const string name, const string team, int back_number)
    {
        name_ = name;
        team_ = team;
        back_number_ = back_number;
    }

    string GetNameTeam() const 
    {
        return name_ + "'s team is " + team_;
    }

    string GetNameBackNumber() const 
    {
        return name_ + "'s back number is " + to_string(back_number_);
    }

private:
    string name_;
    string team_;
    int back_number_;
};

int main()
{
    PlayerInfo player_info;
    player_info.SetValue("Ronaldo", "Juventus", 7);

    cout << player_info.GetNameTeam() << endl;
    cout << player_info.GetNameBackNumber() << endl;

    return 0;
}