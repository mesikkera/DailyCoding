#include <iostream>
#include <vector>

using namespace std;

class MyArray 
{
private:
	vector<int> list;
public:
	void add_list(int const&);
	void delete_last_list(void);
	void show_list(void);
};

void MyArray::add_list(int const& element)
{
	list.push_back(element);
}

void MyArray::delete_last_list(void)
{
	list.pop_back();
}

void MyArray::show_list(void)
{
	cout << "[MyArray list look up]" << endl;
	for(vector<int>::iterator i = list.begin(); i != list.end(); ++i)
		cout << *i << endl;
}

int main()
{
	MyArray array1;
	array1.add_list(1);
	array1.add_list(2);
	array1.add_list(3);
	array1.add_list(4);
	array1.add_list(5);

	array1.show_list();

	array1.delete_last_list();
	array1.delete_last_list();

	array1.show_list();

	return 0;
}