#include <iostream>

using namespace std;

class Point
{
	int x;
	int y;

public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	void Print() const { cout << x << ", " << y << endl; }

	const Point operator+(const Point& arg) const
	{
		Point pt;
		pt.x = this->x + arg.x;
		pt.y = this->y + arg.y;

		return pt;
	}

	const Point operator-(const Point& arg) const
	{
		Point pt;
		if (this->x > arg.x)
			pt.x = this->x - arg.x;
		else
			pt.x = arg.x - this->x;

		if(this->y > arg.y)
			pt.y = this->y - arg.y;
		else 
			pt.y = arg.y - this->y;

		return pt;
	}

	const Point& operator++()		// 전위 ++ 연산자 
	{
		++x;
		++y;
		return *this;

	}

	const Point& operator++(int)	// 후위 ++ 연산자
	{
		x++;
		y++;
		return *this;
	}
};

int main()
{
	Point p1(2, 3), p2(5, 5);
	Point p3, p4;
	Point result;

	p3 = p1 + p2;
	p3.Print(); 
	p4 = p1 - p2;		// p1.operator-(p2); 와 동일.
	p4.Print();

	++p1;				// p1.operator++(); 와 동일.
	p2++;				// p2.operator++(int); 와 동일.

	result = ++p1;		// p1.operator++();와 동일.
	p1.Print();
	result.Print();

	result = p2++;
	p2.Print();
	result.Print();
}