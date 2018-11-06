#include <iostream>

using namespace std;

class MyException {
	int myValue;

public:
	MyException(int value) {
		myValue = value;
	}
	void exceptionResult() {
		if(myValue < 10) 
			cout << "10 이상의 값을 입력하세요." << endl;
		else if (myValue > 20)
			cout << "20 이하의 값을 입력하세요." << endl;
		else if (myValue % 7 != 0)
			cout << "7의 배수 값을 입력하세요." << endl;
	}
};

int main() {
	int value;
	try {
		cout << "10과 20사이의 7의 배수를 입력하세요." << endl;
		cin >> value;

		if(value < 10 | value > 20 | value % 7 != 0)
			throw MyException(value);

		cout << "정답!! 10과 20 사이의 7의 배수는 " << value << " 입니다." << endl;
	} catch (MyException e) {
		e.exceptionResult();
	}
	return 0;
}