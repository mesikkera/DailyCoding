#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	cout << "v[0] : " << v[0] << endl;
	cout << "v.at(0) : " << v.at(0) << endl;
	cout << "v[1] : " << v[1] << endl;
	cout << "v.at(1) ; " << v.at(1) << endl;

	return 0;
}