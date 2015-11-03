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
	void introduce()
	{
		cout << "������ �̸�: " << name << endl;
		cout << "������ ����: " << age << endl;
	}
};

int main(void)
{
	Person person("���", 100);
	person.introduce();

	Mong mong("����", 30, 3);
	mong.introduce();

	return 0;
}