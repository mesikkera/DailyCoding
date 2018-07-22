#include <iostream>
#include <string>

using namespace std;

class FriendInfo
{
public:
    FriendInfo()
    {
        name_ = "Cristiano Ronaldo";
    }

public:
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

    cout << friend_info.GetName() << endl;
    
    return 0;
}