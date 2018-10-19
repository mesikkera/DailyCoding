#include <iostream>
using namespace std;

class Chulsoo 
{
private:
    int age;

public:
    Chulsoo(int age) : age(age)
    {
        cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
    }

    void introduce()
    {
        cout << "철수의 나이는 " << age << "세 입니다." << endl;
    }

    friend Chulsoo operator+(const Chulsoo& chulsooObj1, const Chulsoo& chulsooObj2);
};

int main(void)
{
    Chulsoo chulsoo1(30);
    Chulsoo chulsoo2(15);
    chulsoo1.introduce();
    chulsoo2.introduce();

    Chulsoo chulsooAdd = 3 + chulsoo1;
    chulsooAdd.introduce();

    return 0;
}

Chulsoo operator+(const Chulsoo& chulsooObj1, const Chulsoo& chulsooObj2)
{
    cout << "operator+()" << endl;
    Chulsoo chulsoo(chulsooObj1.age + chulsooObj2.age);
    return chulsoo;
}