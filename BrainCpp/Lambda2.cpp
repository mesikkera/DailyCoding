#include <iostream>
using namespace std;

class Chulsoo 
{
public:
    int count;              // 철수가 스테이크를 먹는 횟수
};

int main(void)
{
    Chulsoo chulsoo;
    chulsoo.count = 1;

    for(int i = 0; i < 10; i++)
    {
        // 지정된 기본 캡쳐 모드가 없기 때문에 'chulsoo'을(를) 암시적으로 캡쳐할 수 없습니다.
        //[](int steakWeight){ cout << "eatLambda()::철수는 " << chulsoo.count << "번 째" << steakWeight << "g짜리 스테이크를 먹는다." << endl;} (1000);

        // 'count'는 const 개체를 통해 액세스 되고 있으므로 수정할 수 없습니다.
        // [=](int steakWeight){ cout << "eatLambda()::철수는 " << chulsoo.count++ << "번째 " << steakWeight << "g짜리 스테이크를 먹는다." << endl;} (1000);
        
        // mutable 속성을 사용하면 값으로 전달받아서 캡처하는 [=]일 때도 람다 함수 안에서 외부 변수를 수정할 수 있다.
        [=](int steakWeight) mutable { cout << "eatLambda()::철수는 " << chulsoo.count++ << "번째 " << steakWeight << "g짜리 스테이크를 먹는다." << endl;} (1000);
        
        // 람다함수 내부에서 외부 변수를 수정할 수 있게 하려면 [&] 캡처를 사용해야 한다.
        [&](int steakWeight){ cout << "eatLambda()::철수는 " << chulsoo.count++ << "번 째" << steakWeight << "g짜리 스테이크를 먹는다." << endl;} (1000);
    }
    return 0;
}
