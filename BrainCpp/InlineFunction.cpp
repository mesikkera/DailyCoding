#include <iostream>
using namespace std;

class Chulsoo 
{
public:
    void Eat(int SteakWeight);
    inline void EatInline(int SteakWeight);
};

int main(void)
{
    Chulsoo chulsoo;
    chulsoo.Eat(500);
    chulsoo.EatInline(500);
}

void Chulsoo::Eat(int SteakWeight)
{
    cout << "Eat() :: 철수는 " << SteakWeight << "g 짜리 스테이크를 먹는다." << endl;
}

inline void Chulsoo::EatInline(int SteakWeight)
{
    cout << "EatInline() :: 철수는 " << SteakWeight << "g 짜리 스테이크를 먹는다." << endl;
}