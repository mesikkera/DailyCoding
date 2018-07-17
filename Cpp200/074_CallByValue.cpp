#include <iostream>

using namespace std;

void Func(int arg)
{
    cout << "Before Addition : " << arg << endl;
    arg += 10;
    cout << "After Addition : " << arg << endl;
}

int main()
{
    int year = 10;
    
    // Call by Value는 인자로 넘어온 값을 내부적으로 복사해서 사용.
    // year 변수에 직접 10을 더하는 것이 아니라 
    // 내부적으로 복사한 값에 10을 더한 셈.
    // 따라서 year 변수의 값은 변함이 없다.
    Func(year);

    cout << "After Call By Value : " << year << endl;

    return 0;
}