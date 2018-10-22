#include <iostream>
#include <memory>
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
    // Chulsoo* chulsooPtr2 = new Chulsoo(32);
    // chulsooPtr2->introduce();
    // delete chulsooPtr2;

    // auto_ptr<Chulsoo> chulsooSmptr(new Chulsoo(32));
    // chulsooSmptr->introduce();

    unique_ptr<Chulsoo> chulsooSmptr1(new Chulsoo(32)); 
    chulsooSmptr1 -> introduce();
    cout << "auto_ptr<Chulsoo> 타입간 복사 생성자 호출 후" << endl;
    unique_ptr<Chulsoo> chulsooSmptr2 = chulsooSmptr1;
    chulsooSmptr1 -> introduce();
    chulsooSmptr2 -> introduce();

return 0;
}

void Chulsoo::introduce()
{
    cout << "철수 나이 : " << age << endl;
}