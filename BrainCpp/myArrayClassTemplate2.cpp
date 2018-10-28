#include <iostream>
#include <vector>

using namespace std;

template <typename T, int init>
class MyArray
{
private:
	vector<T> list;
public:
	MyArray()
	{
		for(int i = 0; i < init; ++i)
			list.push_back(i);
	}
	void add_list(T const&);
	void delete_last_list(void);
	void show_list(void);
};

template<typename T, int init>
void MyArray<T, init>::add_list(T const& element)
{
	list.push_back(element);
}

template <typename T, int init>
void MyArray<T, init>::delete_last_list(void)
{
	list.pop_back();
}

template <typename T, int init>
void MyArray<T, init>::show_list(void) 
{
	cout << "[MyArray list look up]" << endl;
	for(typename vector<T>::iterator i = list.begin(); i != list.end(); ++i)
		cout << *i << "  ";
	cout << "\n";
}

int main()
{
	MyArray<int, 3> array1;
	array1.add_list(1);
	array1.add_list(2);
	array1.add_list(3);
	array1.add_list(4);
	array1.add_list(5);

	array1.show_list();

	array1.delete_last_list();
	array1.delete_last_list();

	array1.show_list();

	MyArray<double, 4> array2;
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