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
    
    return 0;

}