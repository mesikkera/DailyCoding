#include <iostream>
#include <string.h>
using namespace std;

class Chulsoo 
{
private:
    char* name;
    int* age;

public:
    Chulsoo (char* name, int age)
    {
        this->name = new char[strlen(name) + 1];
        strlcpy(this->name, name, strlen(name) + 1);
        this->age = new int;
        *this->age = age;
        cout << "Chulsoo::Chulsoo(name) 생성자 완료" << endl;
    }
    ~Chulsoo()
    {
        delete[] name;
        delete age;
        cout << "Chulsoo::~Chulsoo() 소멸자 완료" << endl;
    }
    void introduce();
};

int main(void)
{
    Chulsoo chulsoo("철수", 32);
    chulsoo.introduce();
    return 0;
}

void Chulsoo::introduce()
{
    cout << "이름 : " << name << endl;
    cout << "나이 : " << *age << endl;
}