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
	}
	virtual void introduce()
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
	}
	void write()
	{
		cout << "ö���� å�� ����." << endl;
	}
	void introduce()
	{
		cout << "������ �̸�: " << name << endl;
		cout << "������ ����: " << age << endl;
		cout << "���̰� �� å�� ��: " << numOfBooks << endl;
	}
};

int main(void)
{
	cout << "====== ( Mong -> Person) ��ĳ����(����) ======" << endl;
	Mong mongUpRef = Mong("����", 30, 3);
	Person& personUpRef = mongUpRef;
	personUpRef.introduce();

	cout << "====== ( Mong -> Person) ��ĳ����(������) ======" << endl;
	Person* personUpPtr = new Mong("����", 30, 3);
	personUpPtr->introduce();

	return 0;
}