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
	void operator+(Point arg)
	{
		cout << "operator+() 함수 호출" << endl;
	}
};

int main()
{
	Point p1(2, 3), p2(2, 5);
	p1 + p2;
	return 0;
}