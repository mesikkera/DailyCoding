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
    Chulsoo* chulsooPtr1 = (Chulsoo*)malloc(sizeof(Chulsoo));
    chulsooPtr1->setAge(32);
    chulsooPtr1->introduce();

    free(chulsooPtr1);
    return 0;
}

void Chulsoo::introduce()
{
    cout << "철수 나이 : " << age << endl;
}