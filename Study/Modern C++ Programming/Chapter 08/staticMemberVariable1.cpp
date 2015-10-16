#include <iostream>
using namespace std;

class Chulsoo
{
private:
	int age;
	static int chulsooPrivateCounter;
protected:
	static int chulsooProtectedCounter;
public:
	static int chulsooPublicCounter;
	Chulsoo(int age) : age(age)
	{
		chulsooPrivateCounter++;
		chulsooProtectedCounter++;
		chulsooPublicCounter++;
	}
}