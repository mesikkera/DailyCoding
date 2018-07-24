#include <iostream>
using namespace std;

struct FuncObject 
{
public:
    void operator() (int arg) const
    {
        cout << "정수 : " << arg << endl;
    }

    void operator() (int arg1, int arg2) const 
    {
        cout << "정수 : " << arg1 << ", " << arg2 << endl;
    }

    void operator() (int arg1, int arg2, int arg3) const 
    {
        cout << "정수 : " << arg1 << ", " << arg2 << ", " << arg3 << endl;
    }
};

int main()
{
    // 객체 생성 후 호출 (암시적)
    FuncObject print;
    print(10);
    print(10, 20);
    print(10, 20, 30);
    cout << endl;

    // 객체 생성 후 호출 (명시적)
    print.operator()(40);
    print.operator()(40, 50);
    print.operator()(40, 50, 60);
    cout << endl;

    // 임시 객체로 호출(암시적)
    FuncObject()(70);
    FuncObject()(70, 80);
    FuncObject()(70, 80, 90);
    cout << endl;

    // 임시 객체로 호출 (명시적)
    FuncObject().operator()(100);
    FuncObject().operator()(100, 200);
    FuncObject().operator()(100, 200, 300);

    return 0;


}