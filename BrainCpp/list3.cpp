#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> lt;
	list<int> lt2;

	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_front(-10);
	lt.push_front(-20);
	lt.push_front(-30);

	for(auto i = lt.begin(); i != lt.end(); i++)
		cout << *i << " ";
	cout << endl;

	for(auto i = 0; i < 10; i++)
		lt2.push_back(i);

	for(auto i = lt2.begin(); i != lt2.end(); i++)
		cout << *i << " ";
	cout << endl;

	for(auto p = lt.begin(); p != lt.end(); p++)
	{
		if(*p == 10)
		{
			lt.splice(p, lt2);
			break;
		}
	}

	for(auto i = lt.begin(); i != lt.end(); i++)
		cout << *i << " ";
	cout << endl;

	return 0;
}