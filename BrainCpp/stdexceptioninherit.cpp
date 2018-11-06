#include <iostream>
#include <exception>

using namespace std;

class MyException : public exception {
	int myValue;

public:
	MyException(int value) {
		myValue = value;
	}

	virtual const char* what() const throw() {			// 멤버 함수 오버로딩
		if(myValue < 10)
			return "10 이상의 값을 입력하세요.";
		else if (myValue > 20)
			return "20 이하의 값을 입력하세요.";
		else if (myValue % 7 != 0)
			return "7의 배수 값을 입력하세요.";
		return "잘못된 예외 전달";
	}
};

int main() {
	int value;
	try {
		cout << "10과 20사이의 7의 배수를 입력하세요: ";
		cin >> value;

		if(value < 10 || value > 20 || value % 7 != 0)
			throw MyException(value);

		cout << "정답! 10과 20사이의 7의 배수는" << value << "입니다." << endl;
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	return 0;
}