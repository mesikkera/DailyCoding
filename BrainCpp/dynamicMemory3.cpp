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
    Chulsoo()
    {
        cout << "Chulsoo::Chulsoo() 생성자 완료" << endl;
    }
    ~Chulsoo()
    {
        cout << "Chulsoo::~Chulsoo() 소멸자 완료" << endl;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void introduce();
};

int main(void)
{
    Chulsoo* chulsooPtr2 = new Chulsoo(32);
    chulsooPtr2->introduce();

    delete chulsooPtr2;
    return 0;
}

void Chulsoo::introduce()
{
    cout << "철수 나이 : " << age << endl;
}