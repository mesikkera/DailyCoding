#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point 
{
    int x, y;

public:
    explicit Point(int _x = 0, int _y = 0):x(_x), y(_y) { }
    int GetX() const { return x; }
    int GetY() const { return y; }
};

ostream& operator<<(ostream& out, const Point& arg)
{
    // Point 객체 cout 출력을 위한 연산자 오버로딩
    out << "(" << arg.GetX() << "," << arg.GetY() << ")";
    return out;
}

bool Pred(const Point& left, const Point& right)
{
    // 순열의 비교 기준으로 사용될 이항 조건자
    return left.GetY() < right.GetY();
}

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
    cout << next_permutation(v.begin(), v.end()) << endl;
    cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;   
    cout << next_permutation(v.begin(), v.end()) << endl;
    cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;   
    cout << next_permutation(v.begin(), v.end()) << endl;
    cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;   
    cout << next_permutation(v.begin(), v.end()) << endl;
    cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;   
    cout << next_permutation(v.begin(), v.end()) << endl;
    cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;   
    // 마지막 순열이므로 next_permutation()은 false 반환
    cout << next_permutation(v.begin(), v.end()) << endl;
    cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;   
    
// 조건자 버전의 next_permutation() 알고리즘
    vector<Point> v1;
    v1.push_back(Point(5, 1));
    v1.push_back(Point(7, 2));
    v1.push_back(Point(5, 3));

    cout << "v1: " << v1[0] << " " << v1[1] << " " << v1[2] << endl;
    cout << next_permutation(v1.begin(), v1.end(), Pred) << endl;
    cout << "v1: " << v1[0] << " " << v1[1] << " " << v1[2] << endl;
    cout << next_permutation(v1.begin(), v1.end(), Pred) << endl;
    cout << "v1: " << v1[0] << " " << v1[1] << " " << v1[2] << endl;
    cout << next_permutation(v1.begin(), v1.end(), Pred) << endl;
    cout << "v1: " << v1[0] << " " << v1[1] << " " << v1[2] << endl;
    cout << next_permutation(v1.begin(), v1.end(), Pred) << endl;
    cout << "v1: " << v1[0] << " " << v1[1] << " " << v1[2] << endl;
    cout << next_permutation(v1.begin(), v1.end(), Pred) << endl;
    // Point의 y를 기준으로 마지막 순열이므로 next_permutation()은 false 반환
    cout << "v1: " << v1[0] << " " << v1[1] << " " << v1[2] << endl;
    cout << next_permutation(v1.begin(), v1.end(), Pred) << endl;
    cout << "v1: " << v1[0] << " " << v1[1] << " " << v1[2] << endl;    
    return 0;
}