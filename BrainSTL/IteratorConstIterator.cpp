#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "v[iterator 읽기 가능] : ";
	for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	cout << "v[const iterator 읽기 가능] : ";
	for(vector<int>::const_iterator citer = v.begin(); citer != v.end(); ++citer)
		cout << *citer << " ";
	cout << endl;

	vector<int>::iterator iter = v.begin();
	vector<int>::const_iterator citer = v.begin();

	*iter = 100;	// 쓰기 가능
	// *citer = 100; 	// 쓰기 불가능

// X::iterator, X::const_iterator, const X::iterator, const X::const_iterator 반복자 비교
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	
	vector<int>::iterator iter1 = v1.begin();
	vector<int>::const_iterator citer1 = v1.begin();
	const vector<int>::iterator const_iter1 = v1.begin() + 2;
	const vector<int>::const_iterator const_citer1 = v1.begin() + 3;

	// iter1은 모두 가능
	*iter = 100;				// 가리키는 원소 변경 가능
	++iter;						// 반복자 변경 가능

	// citer1
	// *citer1 = 200;			// 가리키는 원소 변경 불가능
	++citer1;					// 반복자 변경 가능

	// const_iter1 
	*const_iter1 = 300;			// 카리키는 원소 변경 가능
	// ++const_iter1;			// 반복자 변경 불가능

	// const_citer1
	// *const_citer1 = 400;		// 가리키는 원소 변경 불가능
	// ++const_citer1;			// 반복자 변경 불가능

	return 0; 
}