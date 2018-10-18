#include <iostream>
using namespace std;

class Chulsoo 
{
private:
    int age;
    static int chulsooPrivateCounter;

protected:
    static int chulsooProtectedCounter;

public:
    static int chulsooPublicCounter;
    Chulsoo (int age) : age(age)
    {
        chulsooPrivateCounter++;
        chulsooProtectedCounter++;
        chulsooPublicCounter++;
        cout << "Chulsoo::Chulsoo(age) 생성자로 만들어지는 " << chulsooPrivateCounter << "(Private)번째 생성 완료" << endl;
        cout << "Chulsoo::Chulsoo(age) 생성자로 만들어지는 " << chulsooProtectedCounter << "(Protected)번째 생성 완료" << endl;
        cout << "chulsoo::Chulsoo(age) 생성자로 만들어지는 " << chulsooPublicCounter << "(Public)번째 생성 완료" << endl;
    }
};

int Chulsoo::chulsooPrivateCounter = 0;
int Chulsoo::chulsooProtectedCounter = 0;
int Chulsoo::chulsooPublicCounter = 0;

class Younghee 
{
private:
    int age;

public:
    Younghee(int age) : age(age) 
    {
        // Chulsoo::chulsooPrivateCounter++;
        // Chulsoo::chulsooProtectedCounter++;
        Chulsoo::chulsooPublicCounter++;
        cout << "Younghee::Younghee(age) 생성자로 만들어지는" << Chulsoo::chulsooPublicCounter << "번째 객체 생성 완료" << endl;
    }
};

int main(void)
{
    Chulsoo chulsoo1(32);
    Chulsoo chulsoo2(32);
    Younghee younghee1(32);
    Younghee younghee2(32);
    return 0;
}