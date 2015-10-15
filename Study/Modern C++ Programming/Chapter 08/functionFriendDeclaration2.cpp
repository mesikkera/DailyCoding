#include <iostream>
using namestace std;

class Chulsoo;

class Younghee
{
private:
	int age;
public:
	Younghee(int age) : age(age)
	{
		cout << "Younghee::Younghee(age) 생성자 완료" << endl;
	}
	void introduce()
	{
		cout << "영희 나이: " << age << endl;
	}
	void whoisOlder(const Chulsoo & chulsooObj);
	friend void howOldAreYou(const Chulsoo & chulsooObj, const Younghee & youngheeObj);
};

class Chulsoo
{
private:
	int age;
public:
	Chulsoo(int age) : age(age)
	{
		cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
	}

	void introduce()
	{
		cout << "철수 나이: " << age << endl;
	}
	friend void Younghee : whoIsOlder(const Chulsoo & chulsooObj);
	friend void howOldAreYou(const Chulsoo & chulsooObj, const Younghee & youngheeobj);
};

void Younghee::whoisOlder(const Chulsoo & chulsooObj)
{
	cout << "영희는 철수보다 " << ((age > chulsooObj.age) ? "나이가 많다" : "나이가 같거나 적다") << endl;
}

void howOldAreYou(const Chulsoo & chulsooObj, const Younghee & youngheeObj)
{
	cout << "철수는 " << chulsooObj.age << "살 입니다." << endl;
	cout << "영희는 " << youngheeObj.age << "살 입니다." << endl;
}

int main(void)
{
	Chulsoo chulsoo1(32);
	chulsoo1.introduce();
	Younghee younghee1(32);
	younghee1.introduce();

	younghee1.whoisOlder(chulsoo1);

	howOldAreYou(chulsoo1, younghee1);
	return 0;
}
