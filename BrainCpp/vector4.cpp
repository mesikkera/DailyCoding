#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v(5);

	v.push_back(10);
	v.push_back(20);

	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	for(auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	for(vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	return 0;
}