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

		//생성자
		Point();
};

void Point::Print()
{
	// 클래스의 멤버 변수와 동일한 변수명
	// int x = 333;
	cout << " ( " << x << ", " << y << " )\n";
}

Point::Point()
{
	x = 0;
	y = 0;
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

	// pt1을 사용하여 새로운 pt3을 초기화
	Point pt3 = pt1;

	// pt3의 내용을 출력
	pt3.Print();

	// pt2을 pt3에 대입
	pt3 = pt2;

	// pt3의 내용을 출력
	pt3.Print();
	
	// 멤버 함수 호출
	// pt1.Print();
	// pt2.Print();
	
	// pt4 생성
	Point pt4;

	// pt4 출력 
	pt4.Print();

	return 0;
}

