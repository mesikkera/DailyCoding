#include <iostream>
#include <vector>

using namespace std;

template <typename T = int>
class MyArray
{
private:
	vector<T> list;
public:
	void add_list(T const&);
	void delete_last_list(void);
	void show_list(void);
};

template <typename T>
void MyArray<T>::add_list(T const& element)
{
	list.push_back(element);
}

template <typename T>
void MyArray<T>::delete_last_list(void)
{
	list.pop_back();
}

template <typename T>
void MyArray<T>::show_list(void)
{
	cout << "[MyArray list look up]" << endl;
	for(typename vector<T>::iterator i = list.begin(); i != list.end(); ++i)
			cout << *i << "  ";
	cout << endl;
}

int main()
{
	MyArray<double> array1;
	array1.add_list(1.1);
	array1.add_list(2.2);
	array1.add_list(3.3);
	array1.add_list(4.4);
	array1.add_list(5.5);

	array1.show_list();

	array1.delete_last_list();
	array1.delete_last_list();

	array1.show_list();

	MyArray<> array2;
	array2.add_list(1.1);
	array2.add_list(2.2);
	array2.add_list(3.3);
	array2.add_list(4.4);
	array2.add_list(5.5);

	array2.show_list();

	array2.delete_last_list();
	array2.delete_last_list();

	array2.show_list();

	return 0;
}