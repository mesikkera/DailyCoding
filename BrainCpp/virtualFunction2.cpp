#include <iostream>
using namespace std;

class Person 
{
protected:
    char* name;
    int age;
public:
    Person(char* name, int age)
    {
        this->name = new char[strlen(name) + 1];
        strlcpy(this->name, name, strlen(name) + 1);
        this->age = age;
        cout << "Person::Person(name, age) 생성자 호출" << endl;
    }
    virtual ~Person()
    {
        delete[] name;
        cout << "Person::~Person() 소멸자 호출" << endl;
    }
    virtual void introduce()
    {
        cout << "Person의 이름 : " << name << endl;
        cout << "Person의 나이 : " << age << endl;
    }
};

class Chulsoo : public Person 
{
private:
    char* bookName;
public:
    Chulsoo(char* name, int age, char* bookName) : Person(name, age)
    {
        this->bookName = new char[strlen(bookName)+1];
        strlcpy(this->bookName, bookName, strlen(bookName)+1);
        cout << "Chulsoo::Chulsoo(name, age, bookName)" << endl;
    }
    ~Chulsoo()
    {
        delete[] bookName;
        cout << "Chulsoo::~Chulsoo() 소멸자 호출" << endl;
    }
    void introduce()
    {
        cout << "철수의 이름: " << name << endl;
        cout << "철수의 나이: " << age << endl;
        cout << "철수가 쓴 책이름: " << bookName << endl;
    }
};

int main(void)
{
    Person* personPtr = new Chulsoo("철수", 32, "C++");
    personPtr->introduce();
    delete personPtr;
    return 0;
}