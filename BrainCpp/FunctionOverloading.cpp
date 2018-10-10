#include <iostream>
using namespace std;

class Chulsoo 
{
public:
    void Eat(void);
    void Eat(int SteakNum);
    void Eat(double SteaWeight);
    void Eat(int SteakNum1, int SteakNum2);
};

int main(void)
{
    Chulsoo chulsoo;
    chulsoo.Eat();
    chulsoo.Eat(20000);
    chulsoo.Eat(500.5);
    chulsoo.Eat(20000, 30000);
    return 0;
}

void Chulsoo::Eat(void)
{
    cout << "철수는 스테이크를 먹는다." << endl;
}

void Chulsoo::Eat(int SteakNum)
{
    cout << "철수는 " << SteakNum << "원짜리 스테이크를 먹는다." << endl;
}

void Chulsoo::Eat(double SteakWeight)
{
    cout << "철수는 " << SteakWeight << "g 짜리 스테이크를 먹는다." << endl;
}

void Chulsoo::Eat(int SteakNum1, int SteakNum2)
{
    cout << "철수는 " << SteakNum1 << "원 짜리 스테이크를 먹고, " << SteakNum2 << "원 짜리 스테이크를 먹는다." << endl;
}