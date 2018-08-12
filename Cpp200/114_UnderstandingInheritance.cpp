#include <iostream>
#include <string>

using namespace std;

class Info 
{
public:
    Info() {}

public:
    string name_;
    int back_number_;
};

class GoodPlayer : public Info
{
public:
    GoodPlayer(const string position) : position_(position) {}
    void Display()
    {
        cout << position_ << " " << name_ << " " << "Back Number : " << back_number_ << endl;
    }

private:
    string position_;
};

class BadPlayer : public Info
{
public:
    BadPlayer(const string team) : team_(team){}
    void Display()
    {
        cout << back_number_ << " " << name_ << " " << "Team: " << team_ << endl;
    }

private:
    string team_;
};

int main()
{
    GoodPlayer player1("Forward");
    player1.name_ = "Ronaldo";
    player1.back_number_ = 7;

    BadPlayer player2("Barcelona");
    player2.name_ = "Messi";
    player2.back_number_ = 10;

    player1.Display();
    player2.Display();

    return 0;
}