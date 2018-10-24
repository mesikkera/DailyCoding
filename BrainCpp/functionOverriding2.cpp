#include <iostream>
using namespace std;

#define NAME_LEN 20

class Person 
{
protected:
    char name[NAME_LEN];
    int age;
public:
    Person(char* name, int age) 
    {
        strlcpy(this->name, name, NAME_LEN);
        this->age = age;
        cout << "Person::Person(name, age) 생성자 완료" << endl;
    }
    ~Person()
    {
        cout << "Person::~Person() 소멸자 완료" << endl;
    }
    void introduce()
    {
        cout << "Person의 이름 : " << name << endl;
        cout << "Person의 나이 : " << age << endl;
    }
    void eat()
    {
        cout << "Person은 먹는다." << endl;
    }
    void sleep()
    {
        cout << "Person은 잔다." << endl;
    }
};

class Chulsoo : public Person 
{
private:
    int numOfBooks;
public:
    Chulsoo(char* name, int age, int numOfBooks) : Person(name, age) 
    {
        this->numOfBooks = numOfBooks;
        cout << "Chulsoo::Chulsoo(name, age, numOfBooks) 생성자 완료" << endl;
    }
    ~Chulsoo()
    {
        cout << "Chulsoo::~Chulsoo() 소멸자 완료" << endl;
    }
    void introduce()
    {
        cout << "철수의 이름 : " << name << endl;
        cout << "철수의 나이 : " << age << endl;
    }
};

int main()
{
    Person person("사람", 100);
    person.introduce();

    Chulsoo chulsoo("철수", 32, 3);
    chulsoo.introduce();
    return 0;
}