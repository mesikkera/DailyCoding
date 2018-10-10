#include <iostream>
using namespace std;

class Chulsoo 
{
public:
    void Eat();
};

void Chulsoo::Eat()
{
    cout << "철수는 먹는다." << endl;
}

int main(void)
{
    Chulsoo chulsoo;
    chulsoo.Eat();
    return 0;
}