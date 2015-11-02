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
		cout << "Person::Person(name, age) ������ �Ϸ�" << endl;
	}
	~Person()
	{
		cout << "Person::~Person() �Ҹ��� �Ϸ�" << endl;
	}
	void introduce()
	{
		cout << "Person�� �̸�: " << name << endl;
		cout << "Person�� ����: " << age << endl;
	}
	void eat()
	{
		cout << "Person�� �Դ´�." << endl;
	}
	void sleep()
	{
		cout << "Person�� �ܴ�." << endl;
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
		cout << "Mong::Mong(name, age, numOfBooks) ������ �Ϸ�" << endl;
	}
	~Mong()
	{
		cout << "Mong::~Mong() �Ҹ��� �Ϸ�" << endl;
	}
	void write()
	{
		cout << "���̴� å�� ����." << endl;
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
		cout << "Yoon::Yoon(name, age, numofFlowers) ������ �Ϸ�" << endl;
	}
	~Yoon()
	{
		cout << "Yoon::~Yoon() �Ҹ��� �Ϸ�" << endl;
	}
	void shopping()
	{
		cout << "���̴� ������ �Ѵ�." << endl;
	}
};

int main(void)
{
	cout << "=====Person ��ü ���� ��=====" << endl;
	Person person("���", 100);
	person.introduce();
	person.eat();
	person.sleep();
	cout << "=====Person ��ü ���� ��=====" << endl;
	cout << "" << endl;
	cout << "=====Mong ��ü ���� ��=====" << endl;
	Mong mong("����", 30, 3);
	mong.introduce();
	mong.eat();
	mong.sleep();
	mong.write();
	cout << "=====Mong ��ü ���� ��=====" << endl;
	cout << "" << endl;
	cout << "=====Yoon ��ü ���� ��=====" << endl;
	Yoon yoon("����", 35, 10);
	yoon.introduce();
	yoon.eat();
	yoon.sleep();
	yoon.shopping();
	cout << "=====Yoon ��ü ���� ��=====" << endl;
	return 0;
}