#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v(5, 1);

	v.push_back(10);
	v.push_back(20);

	for(auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	return 0;
}