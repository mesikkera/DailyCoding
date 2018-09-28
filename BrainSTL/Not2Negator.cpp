#include <iostream>
#include <functional>
using namespace std;

int main()
{
	less<int> oLess;
	binary_negate<less<int>> negate = not2(less<int>());

	cout << negate(5, 10) << ':' << not2(oLess)(5, 10) << ':' << not2(less<int>())(5, 10) << endl;
	return 0;
}

