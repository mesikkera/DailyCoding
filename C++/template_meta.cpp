#include <iostream>

template <class _Ty>
struct is_int { enum _value_ { value = false }; };
template <>
struct is_int<int> { enum _value_ { value = true }; };

int main(void)
{
	using std::cout;
	using std::endl;

	cout << is_int<bool>::value << endl;		// 0
	cout << is_int<float>::value << endl;		// 0
	cout << is_int<int>::value << endl;			// 1

	return 0;
}