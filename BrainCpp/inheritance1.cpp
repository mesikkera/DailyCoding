#include <iostream>
using namespace std;

#define NAME_LEN 20

class Person 
{
private:
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
};