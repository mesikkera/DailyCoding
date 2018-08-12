#include <iostream>
using namespace std;

class WhoAmI
{
public:
    int id;

    WhoAmI(int id_arg);
    void ShowYourself() const;
};

WhoAmI::WhoAmI(int id_arg)
{
    id = id_arg;
}

void WhoAmI::ShowYourself() const
{
    cout << "{ ID = " << id << ", this = " << this << "}\n";
}

int main()
{
    // 3개의 객체 생성
    WhoAmI obj1(1);
    WhoAmI obj2(2);
    WhoAmI obj3(3);

    // 객체들의 정보 출력
    obj1.ShowYourself();
    obj2.ShowYourself();
    obj3.ShowYourself();

    // 객체들의 주소 출력
    cout << "&obj1 = " << &obj1 << endl;
    cout << "&obj2 = " << &obj2 << endl;
    cout << "&obj3 = " << &obj3 << endl;

    return 0;
}