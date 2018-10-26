#include <iostream>
using namespace std;

#define NAME_LEN 20

class Person 
{
protected: 
	char name[NAME_LEN];
	int age;
public: 
	Person(char* name, int age) : age(age)
	{
		strcpy(this->name, name);
	}
	virtual void introduce() = 0;
	virtual void eat() = 0;
	virtual void sleep();
};

void Person::sleep()
{
	cout << "사람은 잔다." << endl;
}

class Chulsoo : public Person 
{
private:
	int numOfBooks;
public: 
	Chulsoo(char* name, int age, int numOfBooks) : Person(name, age), numOfBooks(numOfBooks) { }
	virtual void introduce()
	{
		cout << "철수 이름은 : " << name << endl;
		cout << "철수 나이는 : " << age << endl;
		cout << "철수가 쓴 책의 수는 : " << numOfBooks << endl;
	}
	virtual void eat()
	{
		cout << "철수는 먹는다." << endl;
	}
	virtual void sleep() 
	{
		cout << "철수는 잔다." << endl;
	}
}; 

int main(void)
{
	Person * person = new Chulsoo("철수", 32, 3);
	person->introduce();
	person->eat();
	person->sleep();
	return 0;
}