#include <iostream>
using namespace std;

class Chulsoo
{
private:
	int age;
public:
	Chulsoo(int age) :age(age)
	{
		cout << "Chulsoo::Chulsoo(age) ������ �Ϸ�" << endl;
	}
	void introduce()
	{
		cout << "ö���� ���̴� " << age << "�� �Դϴ�." << endl;
	}
	Chulsoo operator+(const Chulsoo& chulsooObj);
	Chulsoo operator-(const Chulsoo& chulsooObj);
	Chulsoo operator*(const Chulsoo& chulsooObj);
	Chulsoo operator/(const Chulsoo& chulsooObj);
};

int main(void)
{
	Chulsoo chulsoo1(30);
	Chulsoo chulsoo2(15);
	chulsoo1.introduce();
	chulsoo2.introduce();

	Chulsoo chulsooAdd = chulsoo1 + chulsoo2;
	chulsooAdd.introduce();

	Chulsoo chulsooSub = chulsoo1 - chulsoo2;
	chulsooSub.introduce();

	Chulsoo chulsooMul = chulsoo1 * chulsoo2;
	chulsooMul.introduce();

	Chulsoo chulsooDiv = chulsoo1 / chulsoo2;
	chulsooDiv.introduce();

	return 0;
}

Chulsoo Chulsoo::operator+(const Chulsoo& chulsooObj)
{
	cout << "Chulsoo::operator+()" << endl;
	Chulsoo chulsoo(this->age + chulsooObj.age);
	return chulsoo;
}

Chulsoo Chulsoo::operator-(const Chulsoo& chulsooObj)
{
	cout << "Chulsoo::operator-()" << endl;
	Chulsoo chulsoo(this->age - chulsooObj.age);
	return chulsoo;
}

Chulsoo Chulsoo::operator*(const Chulsoo& chulsooObj)
{
	cout << "Chulsoo::operator*()" << endl;
	Chulsoo chulsoo(this->age * chulsooObj.age);
	return chulsoo;
}

Chulsoo Chulsoo::operator/(const Chulsoo& chulsooObj)
{
	cout << "Chulsoo::operator/()" << endl;
	Chulsoo chulsoo(this->age / chulsooObj.age);
	return chulsoo;
}