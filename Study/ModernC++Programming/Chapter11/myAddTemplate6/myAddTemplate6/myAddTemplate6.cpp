#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
T const add(T const& a, T const& b) {
	cout << "typename T" << endl;
	return a + b;
}

template <>
char* const add<char*>(char* const& a, char * const& b) {
	cout << "specialized" << endl;
	return strcat(a, b);
}

char* const add(char* const& a, char* const& b) {
	cout << "overloading" << endl;
	return strcat(a, b);
}

