#include <iostream>
using namespace std;

void Sub()
{
    // static 키워드를 사용해서 지역변수 정의
    static int n = 0;
    
    // n을 1 증가시킨 후 출력
    ++n;
    cout << "n = " << n << endl;
}

class Test 
{
public:
    void Func()
    {
        static int a = 0;
        cout << "a = " << ++a << endl;
    }
};

int main()
{
    // Sub함수를 여러번 출력
    Sub();
    Sub();
    Sub();
    Sub();
    Sub();
    cout << "== TEST ==" << endl;
    Test t1, t2, t3;
    t1.Func();
    t2.Func();
    t3.Func();

    return 0;
}
