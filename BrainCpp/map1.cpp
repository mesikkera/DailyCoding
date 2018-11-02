#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, int> m;

	m.insert(make_pair("A", 10));
	m.insert(make_pair("B", 20));
	m.insert(make_pair("C", 30));
	m.insert(make_pair("D", 40));
	m.insert(make_pair("E", 50));
	m["F"] = 100;

	for(auto i = m.begin(); i != m.end(); ++i) {
		cout << "[" << i -> first << " " << i -> second << "] ";
	}
	cout << endl;

	auto i = m.find("A");
	cout << i -> second << endl;

	return 0;
}