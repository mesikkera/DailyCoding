#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;

    s.insert(50);
    s.insert(30);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(70);
    s.insert(90);

    set<int>::iterator iter;
    for(iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "원소 50의 개수 : " << s.count(50) << endl;
    cout << "원소 100의 개수 : " << s.count(100) << endl;

    // set의 find()
    iter = s.find(30);      // 30의 반복자를 반환
    if(iter != s.end())
        cout << *iter << "이 s에 있다." << endl;
    else 
        cout << "s에 30이 없다" << endl;

    return 0;
}