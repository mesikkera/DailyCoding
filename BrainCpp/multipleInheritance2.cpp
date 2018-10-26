#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person::Person() constructor call" << endl;
	}
	~Person()
	{
		cout << "Person::~Person() destructor call" << endl;
	}
	virtual void write() = 0;
};

class Chulsoo : public virtual Person 
{
public:
	Chulsoo() : Person()
	{
		cout << "Chulsoo::Chulsoo() constructor call" << endl;
	}
	~Chulsoo()
	{
		cout << "Chulsoo::~Chulsoo() destructor call" << endl;
	}
	void write()
	{
		cout << "Write a book" << endl;
	}
};

class Younghee : public virtual Person 
{
public:
	Younghee() : Person()
	{
		cout << "Younghee::Younghee() constructor call" << endl;
	}
	~Younghee()
	{
		cout << "Younghee::~Younghee() destructor call" << endl;
	}
	void write()
	{
		cout << "Does not write a book" << endl;
	}
};

class Youngchul : public Chulsoo, public Younghee 
{
public: 
	Youngchul() : Chulsoo(), Younghee()
	{
		cout << "Youngchul::Youngchul() constructor call" << endl;
	}
	~Youngchul()
	{
		cout << "Youngchul::~Youngchul() destructor call" << endl;
	}
	void write()
	{
		Chulsoo::write();
	}
};

int main(void) 
{
	Youngchul youngchul;
	youngchul.write();
	return 0;
}