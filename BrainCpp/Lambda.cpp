#include <iostream>
using namespace std;

class Chulsoo 
{
public:
    void eat(int steakWeight);
    inline void eatInline(int steakWeight)
    {
        cout << "eatInline() :: 철수는 " << steakWeight << "g 짜리 스테이크를 먹는다. " << endl;
    }
};

int main()
{
    Chulsoo chulsoo;
    chulsoo.eat(1000);
    chulsoo.eatInline(1000);
    [](int steakWeight){cout << "eatLambda() :: 철수는 " << steakWeight << "g 짜리 스테이크를 먹는다." << endl;}(1000);

    return 0;
}

void Chulsoo::eat(int steakWeight)
{
    cout << "eat()::철수는 " << steakWeight << "g 짜리 스테이크를 먹는다." << endl;
}