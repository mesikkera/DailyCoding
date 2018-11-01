#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> lt;

	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);

	for(auto i = lt.begin(); i != lt.end(); i++)
		cout << *i << " ";
	cout << endl;

	lt.push_front(-10);
	lt.push_front(-20);
	lt.push_front(-30);

	for(auto i = lt.begin(); i != lt.end(); i++)
		cout << *i << " ";
	cout << endl;

	return 0;
}