#include <iostream>
using namespace std;

#define NAME_LEN 20

class Person
{
private:
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
};

class Yoon : public Person
{
private:
	int numOfFlowers;
public:
	Yoon(char * name, int age, int numOfFlowers) : Person(name, age)
	{
		this->numOfFlowers = numOfFlowers;
		cout << "Yoon::Yoon(name, age, numofFlowers) 생성자 완료" << endl;
	}
	~Yoon()
	{
		cout << "Yoon::~Yoon() 소멸자 완료" << endl;
	}
	void shopping()
	{
		cout << "윤이는 쇼핑을 한다." << endl;
	}
};

int main(void)
{
	cout << "=====Person 객체 생성 전=====" << endl;
	Person person("사람", 100);
	person.introduce();
	person.eat();
	person.sleep();
	cout << "=====Person 객체 예제 끝=====" << endl;
	cout << "" << endl;
	cout << "=====Mong 객체 생성 전=====" << endl;
	Mong mong("몽이", 30, 3);
	mong.introduce();
	mong.eat();
	mong.sleep();
	mong.write();
	cout << "=====Mong 객체 예제 끝=====" << endl;
	cout << "" << endl;
	cout << "=====Yoon 객체 생성 전=====" << endl;
	Yoon yoon("윤이", 35, 10);
	yoon.introduce();
	yoon.eat();
	yoon.sleep();
	yoon.shopping();
	cout << "=====Yoon 객체 예제 끝=====" << endl;
	return 0;
}