#include <iostream>
using namespace std;

class Point 
{
private:
	int x;
	int y;
public:
	Point (int _x = 0, int _y = 0):x(_x), y(_y) {}
	void Print() const { cout << x << ", " << y << endl; }
	const Point operator+(const Point& arg) const
	{
		Point pt;
		pt.x = this->x + arg.x;
		pt.y = this->y + arg.y;

		return pt;
	}
	// ++전위 연산자 오버로딩
	const Point& operator++ ()
	{
		++x;
		++y;
		return *this;
	}

	// 후위++ 연산자 오버로딩
	const Point operator++(int)
	{
		Point pt(x, y);
		++x;
		++y;
		return pt;
	}
};

class Array
{

};

int main()
{
	Point p1(2, 3), p2(5, 5);
	Point p3;
	
	p3 = p1 + p2;
	p3.Print();
	p3 = p1.operator+ (p2);
	p3.Print();
	return 0;
}