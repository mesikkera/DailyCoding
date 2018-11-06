#include <iostream>

using namespace std;

int main() {
	int a, b;
	int result = 0;

	cout << "a/b를 수행합니다. a, b를 입력하세요. " << endl;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;

	result = a / b;

	cout << "a / b의 결과는 " << result << " 입니다." << endl;

	return 0;
}