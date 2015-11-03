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
	}
	void write()
	{
		cout << "철수가 책을 쓴다." << endl;
	}
	void introduce()
	{
		cout << "몽이의 이름: " << name << endl;
		cout << "몽이의 나이: " << age << endl;
		cout << "몽이가 쓴 책의 수: " << numOfBooks << endl;
	}
};

int main(void)
{
	cout << "====== ( Mong -> Person) 업캐스팅(참조) ======" << endl;
	Mong mongUpRef = Mong("몽이", 30, 3);
	Person& personUpRef = mongUpRef;
	personUpRef.introduce();

	cout << "====== ( Mong -> Person) 업캐스팅(포인터) ======" << endl;
	Person* personUpPtr = new Mong("몽이", 30, 3);
	personUpPtr->introduce();

	return 0;
}