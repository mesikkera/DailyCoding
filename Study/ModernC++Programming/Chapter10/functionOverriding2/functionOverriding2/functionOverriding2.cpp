#include <iostream>
using namespace std;

#define NAME_LEN 20

class Person
{
protected:
	char name[NAME_LEN];
	int age;
public:
	Person(char * name, int age)
	{
		strcpy_s(this->name, name);
		this->age = age;
		cout << "Person::Person(name, age) 생성자 완료" << endl;
	}
	~Person()
	{
		cout << "Person::~Person() 소멸자 완료" << endl;
	}
	void introduce()
	{
		cout << "Person의 이름: " << name << endl;
		cout << "Person의 나이: " << age << endl;
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

class Mong : public Person
{
private:
	int numOfBooks;
public:
	Mong(char * name, int age, int numOfBooks) : Person(name, age)
	{
		this->numOfBooks = numOfBooks;
		cout << "Mong::Mong(name, age, numOfBooks) 생성자 완료" << endl;
	}
	~Mong()
	{
		cout << "Mong::~Mong() 소멸자 완료" << endl;
	}
	void write()
	{
		cout << "몽이는 책을 쓴다." << endl;
	}
	void introduce()
	{
		cout << "몽이의 이름: " << name << endl;
		cout << "몽이의 나이: " << age << endl;
	}
};

int main(void)
{
	Person person("사람", 100);
	person.introduce();

	Mong mong("몽이", 30, 3);
	mong.introduce();

	return 0;
}