#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> fl;
	forward_list<int> fl2 = {1, 2, 3, 4};

	fl.push_front(10);
	fl.push_front(20);
	fl.push_front(30);
	fl.push_front(40);

	for(auto i = fl.begin(); i != fl.end(); i++)
		cout << *i << " ";
	cout << endl;

	for(auto i = fl2.begin(); i != fl2.end(); i++)
		cout << *i << " ";
	cout << endl;

	for(auto i = fl.begin(); i != fl.end(); i++)
	{
		if(*i == 30)
		{
			fl.splice_after(i, fl2);
			break;
		}
	}

	for(auto i = fl.begin(); i != fl.end(); i++)
		cout << *i << " ";
	cout << endl;

	forward_list<int> fl3 = {100, 200, 300, 400};
	auto p = fl.before_begin();
	fl.splice_after(p, fl3);
	for(auto i = fl.begin(); i != fl.end(); i++)
		cout << *i << " ";
	cout << endl;

	return 0;
}