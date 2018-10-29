#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v(6, 1);
	cout << "v.capacity() : " << v.capacity() << " / v.size() : " << v.size() << endl;
	for(auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl << endl;

	v.assign(4, 3);
	cout << "v.capacity() : " << v.capacity() << " / v.size() : " << v.size() << endl;
	for(auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl << endl;

	v[2] = 7;
	for(vector<int>::iterator it = v.begin()+3; it != v.end(); it++)
		*it = 9;

	v.push_back(10);
	v.push_back(20);
	cout << "v.capacity() : " << v.capacity() << " / v.size() : " << v.size() << endl;
	for(auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl << endl;

	v.push_back(30);
	cout << "v.capacity() : " << v.capacity() << " / v.size() : " << v.size() << endl;
	for(auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl << endl;

	v.resize(17);
	cout << "v.capacity() : " << v.capacity() << " / v.size() : " << v.size() << endl;
	for(auto i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl << endl;
}