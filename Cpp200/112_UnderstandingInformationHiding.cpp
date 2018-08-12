#include <iostream>
#include <string>

using namespace std;

class PlayerInfo
{
public:
    PlayerInfo() {};

public:
    void SetValue(const string value)
    {
        if(value.empty() == false)
            value_ = value;
        else
            cout << "Wrong Argument!" << endl;
    }

    string GetValue() const 
    {
        if(value_.empty() == false)
            return value_;
        else
            return "Please, Set Option!";
    }

private:
    string value_;
    int number_;
};

int main()
{
    PlayerInfo player_info1;
    player_info1.SetValue("Ronaldo");

    PlayerInfo player_info2;
    player_info2.SetValue("Messi");

    /* 고의 에러
     error: ‘std::__cxx11::string PlayerInfo::value_’ is private within this context
     player_info1.value_ = "Neymar";
                  ^~~~~~
    112_UnderstandingInformationHiding.cpp:29:12: note: declared private here
     string value_;
            ^~~~~~
    
    player_info1.value_ = "Neymar";
    */

    cout << player_info1.GetValue() << endl;
    cout << player_info2.GetValue() << endl;

    return 0;
}