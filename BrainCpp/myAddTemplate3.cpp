#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
T const add(T const& a, T const& b)
{
	cout << "typename T" << endl;
	return a + b;
}

template <>
char* const add<char*>(char* const& a, char* const& b)
{
	cout << "specialized" << endl;
	return strcat(a, b);
}

char* const add(char* const& a, char* const& b)
{
	cout << "overloading" << endl;
	return strcat(a, b);
}

int main()
{
	int i = 5;
	int j = 10;

	double a = 5.1;
	double b = 10.2;

	char m[20] = "Hello";
	char n[20] = "World";

	cout << i << " + " << j << " = " << add(i, j) << endl;
	cout << a << " + " << b << " = " << add(a, b) << endl;
	cout << add<char*>(m, n) << endl;
	cout << add(m, n) << endl;

	return 0;
}