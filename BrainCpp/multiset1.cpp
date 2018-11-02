#include <iostream>
#include <set>

using namespace std;

int main()
{
	multiset<int> ms;
	multiset<int>::iterator ms_iter;

	ms.insert(10);
	ms.insert(30);
	ms.insert(60);
	ms.insert(20);
	ms.insert(50);
	ms.insert(40);
	ms_iter = ms.insert(40);

	for(auto i = ms.begin(); i != ms.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	cout << "40의 개수: " << ms.count(40) << endl;
	auto f = ms.find(40);
	if(f != ms.end()) {
		cout << *f << endl;
	}

	return 0;
}