#include <iostream>

using namespace std;

int main() {
	int value;
	try {
		cout << "10 이상의 수 입력" << endl;
		cin >> value;

		if (value < 19) {
			throw value;
		} 
	} catch(int e) {
		cout << "예외 발생. 잘못된 입력 값: " << endl;
	}
	return 0;
}