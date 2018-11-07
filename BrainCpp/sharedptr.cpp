#include <iostream>
#include <memory>

using namespace std;

int main() {
	shared_ptr<int> s(new int);						// 참조 카운터 1

	*s = 10;
	cout << "참조 카운터: 1" << endl;
	cout << *s << endl;

	shared_ptr<int> t = s;							// 참조 카운터 2
	*t += 1;

	cout << "참조 카운터: 2" << endl;
	cout << "s의 값: " << *s << endl;
	cout << "s의 주소: " << s << endl;
	cout << "t의 값: " << *t << endl;
	cout << "t의 주소: " << t << endl;

	shared_ptr<int> u = t;							// 참조 카운터 3
	cout << "s의 주소: " << s << endl;
	cout << "t의 주소: " << t << endl;
	cout << "u의 주소: " << u << endl;

	*u += 1;

	cout << *s << endl;
	cout << *t << endl;
	cout << *u << endl;

	return 0;


}