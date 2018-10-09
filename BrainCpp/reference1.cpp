#include <iostream>
using namespace std;

int main()
{
    using salary = double;
    salary peter = 100.12;
    // 참조자 선언은 특정 변수의 별칭을 선언하는 것이므로
    // 반드시 특정 변수로 초기화를 해줘야 한다.
    salary &sangwon = peter;
    cout << "Peter's memory address = " << &peter << endl;
    cout << "sangwon's memory address = " << &sangwon << endl;
    return 0;
}