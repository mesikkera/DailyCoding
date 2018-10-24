#include <iostream>
using namespace std;

#define NAME_LEN 20

class Person 
{
private:
    char name[NAME_LEN];
    int age;

public:
    Person (char* name, int age)
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
        cout << "Chulsoo::Chulsoo(name, age, numOfBools) 생성자 완료" << endl;
    }
    ~Chulsoo()
    {
        cout << "Chulsoo::~Chulsoo() 소멸자 완료" << endl;
    }
    void write()
    {
        cout << "철수는 책을 쓴다." << endl;
    }
};

class Younghee : public Person 
{
private:
    int numOfFlowers;

public:
    Younghee(char* name, int age, int numOfFlowers) : Person(name, age)
    {
        this->numOfFlowers = numOfFlowers;
        cout << "Younghee::Younghee(name, age, numOfFlowers) 생성자 완료" << endl;
    }
    ~Younghee()
    {
        cout << "Younghee::~Younghee() 소멸자 완료" << endl;
    }
    void shopping()
    {
        cout << "영희는 쇼핑을 한다." << endl;
    }
};

int main()
{
    cout << "===Person 객체 생성 전===" << endl;
    Person person("사람", 100);
    person.introduce();
    person.eat();
    person.sleep();
    cout << "===Person 객체 예제 끝===" << endl;
    cout << "===Chulsoo 객체 생성 전===" << endl;
    Chulsoo chulsoo("철수", 32, 3);
    chulsoo.introduce();
    chulsoo.eat();
    chulsoo.sleep();
    chulsoo.write();
    cout << "===Chulsoo 객체 예제 끝===" << endl;
    cout << "===Younghee 객체 생성 전===" << endl;
    Younghee younghee("영희", 30, 10);
    younghee.introduce();
    younghee.eat();
    younghee.sleep();
    younghee.shopping();
    cout << "===Younghee 객체 예제 끝===" << endl;
    return 0;
}

