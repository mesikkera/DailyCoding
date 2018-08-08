#include <iostream>
using namespace std;

// Point 클래스 정의
class Point
{
	public:
		// 멤버 변수
		int x;
		int y;

		// 멤버 함수
		void Print();
		// void Print()
		// {
		// 	// 멤버 변수에서 사용하고 있는 X, Y는 
		// 	// 자기 자신의 멤버 변수를 의미
		// 	cout << " ( " << x << ", " << y << " )\n";
		// }

};

void Point::Print()
{
	// 클래스의 멤버 변수와 동일한 변수명
	int x = 333;
	cout << " ( " << x << ", " << y << " )\n";
}

int main()
{
	// 객체 생성
	Point pt1, pt2;

	// 객체 초기화
	pt1.x = 100;
	pt1.y = 100;
	pt2.x = 200;
	pt2.y = 200;

	// 멤버 함수 호출
	pt1.Print();
	pt2.Print();
	
	return 0;
}

