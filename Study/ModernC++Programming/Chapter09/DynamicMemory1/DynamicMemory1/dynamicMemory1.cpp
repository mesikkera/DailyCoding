#include <iostream>
using namespace std;

class Mong
{
private:
	char * name;
	int * age;
public:
	Mong(char * name, int age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = new int;
		*this->age = age;
		cout << "Mong::Mong(name) 생성자 완료" << endl;
	}
	~Mong()
	{
		delete[] name;
		delete age;
		cout << "Mong::~Mong() 소멸자 완료" << endl;
	}
	void introduce();
};

int main(void)
{
	Mong mong("mong", 30);
	mong.introduce();
	return 0;
}

void Mong::introduce()
{
	cout << "name: " << name << endl;
	cout << "age:  " << *age << endl;
}
