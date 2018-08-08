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
		void Print()
		{
			cout << " ( " << x << ", " << y << " )\n";
		}
};

int main()
{
	return 0;
}

