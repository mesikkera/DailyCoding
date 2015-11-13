#include <iostream>
using namespace std;

void Print(int a, int b)
{
	cout << a << ", " << b << endl;
}

void Print(double a, double b)
{
	cout << a << ", " << b << endl;
}

void Print(const char* a, const char* b)
{
	cout << a << ", " << b << endl;
}

int main()
{
	Print(10, 20);
	Print(0.123, 1.123);
	Print("ABC", "abcde");

	return 0;
}