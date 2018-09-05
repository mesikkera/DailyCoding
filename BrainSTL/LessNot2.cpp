#include <iostream>
#include <functional>               // not2 사용
using namespace std;

int main()
{
    // 임시 less 객체로 비교
    cout << less<int>() (10, 20) << endl;
    cout << less<int>() (20, 20) << endl;
    cout << less<int>() (20, 10) << endl;
    cout << "====================" << endl;
    // 임시 객체 less에 not2 적용
    cout << not2(less<int>()) (10, 20) << endl;
    cout << not2(less<int>()) (20, 20) << endl;
    cout << not2(less<int>()) (20, 10) << endl;
    cout << endl;

    less<int> l;
    cout << l(10, 20) << endl;
    cout << l(20, 20) << endl;
    cout << l(20, 10) << endl;
    cout << "====================" << endl;
    cout << not2(l)(10, 20) << endl;
    cout << not2(l)(20, 20) << endl;
    cout << not2(l)(20, 10) << endl;

    return 0;
}
