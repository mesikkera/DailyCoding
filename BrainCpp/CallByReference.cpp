#include <iostream>
using namespace std;

class Restaurant
{
public:
    int Steak;      // 스테이크 가격
};

class Chulsoo 
{
public:
    int Eat(int&);   
};

// 철수가 먹은 스테이크 가격을 받아서 반환하는 함수 정의
int Chulsoo::Eat(int& SteakNum)
{
    SteakNum = 10000;   // 철수가 10,000원짜리 스테이크를 먹었다고 거짓말
    cout << "철수는 먹는다." << endl;
    return SteakNum;
}

int main(void)
{
    Chulsoo chulsoo;
    Restaurant restaurant;

    restaurant.Steak = 20000;       // 레스토랑에서 철수에게 준 스테이크는 20000원
    cout << "철수는 " << chulsoo.Eat(restaurant.Steak) << "원 짜리 스테이크를 먹었다고 거짓말을 했다." << endl;
    cout << "레스토랑은 철수가 " << restaurant.Steak << "원 짜리 스테이크를 먹었다고 알고 있다." << endl;

    return 0;
}