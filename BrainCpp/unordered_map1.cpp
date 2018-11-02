#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	unordered_map<string, int> um;

	um.insert({"A", 100});
	um.insert(make_pair("B", 200));
	um.insert({ 
		{"C", 1000},
		{"D", 2000}
	});

	for(auto i = um.begin(); i != um.end(); ++i) {
		cout << "[" << i -> first << " " << i ->second << "] ";
	}
	cout << endl;

	auto bc = um.bucket("B");
	for(auto i = um.begin(bc); i != um.end(bc); ++i) { 
		cout << i -> first << ": " << i -> second;
	}
	cout << endl;

	return 0;
}