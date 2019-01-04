#include <iostream>

using namespace std;

class Point
{
	int x;
	int y;

public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	void Print() const { cout << x << ", " << y << endl; }

	const Point operator+(const Point& arg)
	{
		Point pt;
		pt.x = this->x + arg.x;
		pt.y = this->y + arg.y;

	}

	void operator-(Point arg)
	{
		cout << "operator-() 함수 호출" << endl;
	}
};

int main()
{
	Point p1(2, 3), p2(4, 5);
	Point p3;

	p3 = p1 + p2;
	p3.Print(); 
	p1 - p2;		// p1.operator-(p2); 와 동일.
}