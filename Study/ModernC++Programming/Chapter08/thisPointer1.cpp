#include <iostream>
using namespace std;

// this포인터는 객체 자신을 가르키는 포인터
class Chulsoo
{
private:
	int age;
public:
	Chulsoo(int age)
	{
		this->age = age;
		cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
	}

	void setAge(int age)
	{
		this->age = age;
	}

	void introduce()
	{
		cout << "철수의 나이는 " << age << "세 입니다." << endl;
	}

	Chulsoo * returnThisPointer()
	{
		
	}
}