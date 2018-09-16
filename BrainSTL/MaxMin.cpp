#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point 
{
    int x, y;
public:
    explicit Point(int _x = 0, int _y = 0): x(_x), y(_y) { }
    int GetX() const { return x; }
    int GetY() const { return y; }
    void Print() const { cout << '(' << x<< ',' << y << ')' << endl;
    }
};

bool Compare(const Point& left, const Point& right)
{
    if(left.GetX() < right.GetX())
        return true;
    else if (left.GetY() > right.GetY())
        return false;
    else 
        return left.GetY() < right.GetY();
}

bool XCompare(const Point& left, const Point& right)
{
    return left.GetX() < right.GetX();
}

bool YCompare(const Point& left, const Point& right)
{
    return left.GetY() < right.GetY();
}

int main()
{
    int a = 10, b = 20;
    int r;

    r = max(a, b);
    cout << "max : " << r << endl;

    r = min(a, b);
    cout << "min : " << r << endl;

    Point pt1(5, 8), pt2(3, 9);
    Point pt3;

    pt3 = max(pt1, pt2, XCompare);
    cout << "x max : "; pt3.Print();

    pt3 = max(pt1, pt2, YCompare);
    cout << "y max : "; pt3.Print();

// max_element(), min_element() 알고리즘
    vector<int> v;

    v.push_back(30);
    v.push_back(10);
    v.push_back(20);
    v.push_back(50);
    v.push_back(40);

    vector<int>::iterator iter;
    iter = max_element(v.begin(), v.end());
    cout << *iter << endl;

    iter = min_element(v.begin(), v.end());
    cout << *iter << endl;

// 조건자 버전 max_element() 알고리즘
    vector<Point> v1;

    v1.push_back(Point(3,2));
    v1.push_back(Point(2,5));
    v1.push_back(Point(1,5));
    v1.push_back(Point(3,3));
    v1.push_back(Point(3,2));

    vector<Point>::iterator iter1;
    iter1 = max_element(v1.begin(), v1.end(), Compare);
    cout << "max: "; iter1 -> Print();        // 반복자가 가리키는 객체의 멤버는 -> 연산자로 접근
    cout << "max: "; (*iter1).Print();        // 위와 같다.

    return 0;

}