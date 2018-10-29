#include <iostream>
#include <vector>

using namespace std;

template <typename T>
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

template <>
class MyArray<int>
{
private:
	vector<int> list;
public:
	void add_list(int const&);
	void delete_last_list(void);
	void show_list(void);
};

void MyArray<int>::add_list(int const& element)
{
	list.push_back(element);
}

void MyArray<int>::delete_last_list(void)
{
	list.pop_back();
}

void MyArray<int>::show_list(void)
{
	cout << "[MyArray list look up (Specialization for int)]" << endl;
	for(typename vector<int>::iterator i = list.begin(); i != list.end(); ++i)
		cout << *i << "  ";
	cout << endl;
}

int main()
{
	MyArray<int> array1;
	array1.add_list(1);
	array1.add_list(2);
	array1.add_list(3);
	array1.add_list(4);
	array1.add_list(5);

	array1.show_list();
	array1.delete_last_list();
	array1.delete_last_list();
	array1.show_list();

	MyArray<double> array2;
	array2.add_list(1.1);
	array2.add_list(2.2);
	array2.add_list(3.3);
	array2.add_list(4.4);
	array2.add_list(5.5);

	array2.show_list();
	array2.delete_last_list();
	array2.delete_last_list();
	array2.show_list();
}