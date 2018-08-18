#include <iostream>

using namespace std;

// 람다: 캡쳐 블록과 파라미터는 비워놓을 수 있지만 
// []와 ()은 생략 불가
auto func1 = [](){ cout << "Lambda Function" << endl; };
// -> bool : return type (생략 가능)
auto func2 = [](int x, int y) -> bool { return x < y; };

int main()
{
    int x = 2;

    // [=]: 유효 영역 모든 변수에 접근하여 사용할 수 있다는 의미.
    auto func3 = [=](int y) { 
        func1();
        cout << "x < y = " << func2(x, y) << endl;
    };

    func3(4);

    auto func4 = [=](int y) { return x * x + y * y; };

    cout << "x * x + y * y = " << func4(5) << endl;

    return 0;
}