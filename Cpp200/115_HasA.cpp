#include <iostream>

using namespace std;

class Rent 
{
public:
    void Payment() { cout << "임대료를 받습니다." << endl;}
};

class Landload : public Rent 
{
public:
    void GetMoney()
    {
        cout << "건물주라서 ";
        Payment();
    }
};

int main()
{
    Landload master;
    master.GetMoney();

    return 0;
}