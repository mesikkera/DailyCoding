#include <iostream>
using namespace std;

void  Print()
{
    cout << "정적 함수 Print()" << endl;
}

class Point 
{
public:
    void Print()
    {
        cout << "멤버 함수 Print()" << endl;
    }
};

int main()
{
    Point pt;
    Point* p = &pt;

    Print();        // 1. 정적 함수 호출
    pt.Print();     // 2. 객체로 멤버 함수 호출
    p->Print();     // 3. 주소로 멤버 함수 호출
}