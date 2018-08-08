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

		//생성자들
		Point();								// 디폴트 생성자
		Point(int initialX, int initialY);		// 두개의 인자를 가진 생성자
		Point(const Point& pt);					// 복사생성자
};

void Point::Print()
{
	// 클래스의 멤버 변수와 동일한 변수명
	// int x = 333;
	cout << " ( " << x << ", " << y << " )\n";
}

// 디폴트 생성자
Point::Point()
{
	x = 0;
	y = 0;
}

// 인자로 넘어온 값을 사용해서 멤버 변수 초기화
Point::Point(int initialX, int initialY)
{
	x = initialX;
	y = initialY;
}

// 복사생성자
Point::Point(const Point& pt)
{
	cout << "복사 생성자 호출!\n";
	x = pt.x;
	y = pt.y;
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
	// 복사생성자 호출
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

	// pt5 생성
	Point pt5(3, 5);

	// pt5 객체를 생성
	pt5.Print();

	return 0;
}

