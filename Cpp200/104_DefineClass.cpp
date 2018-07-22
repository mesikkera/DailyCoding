#include <iostream>
#include <string>

using namespace std;

class FriendInfo 
{
public:
    void SetName(string name)
    {
        name_ = name;
    }

    string GetName() const
    {
        return name_;
    }

private:
    string name_;
};

int main()
{
    FriendInfo friend_info;
    friend_info.SetName("David Beckham");

    cout << friend_info.GetName() << endl;

    return 0;
}

