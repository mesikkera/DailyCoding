#include <iostream>
using namespace std;

template <typename T>
void Print(T a, T b)
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