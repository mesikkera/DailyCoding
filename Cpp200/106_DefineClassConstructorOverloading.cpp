#include <iostream>
#include <string>

using namespace std;

class FriendInfo
{
public:
    FriendInfo()
    {
        value_ = "Lionel Messi";
    };

    FriendInfo(const string value)
    {
        value_ = value;
    };

    FriendInfo(const int value)
    {
        value_ = "Goal Counter : ";
        value_ += to_string(value);
    };

public:
    string GetValue() const
    {
        return value_;
    }

private:
    string value_;
};

int main()
{
    FriendInfo friend_info1;
    FriendInfo friend_info2("Cristiano Ronaldo");
    FriendInfo friend_info3("1989.01.01");

    cout << friend_info1.GetValue() << endl;
    cout << friend_info2.GetValue() << endl;
    cout << friend_info3.GetValue() << endl;

    return 0;
}

