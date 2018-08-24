#include <typeinfo>

class A
{
    virtual void Func() {};
};

class B : public A
{

};

class C : public B
{

};

int main()
{
    // C객체를 생성해서 A*에 담는다.
    A* pa1 = new C;

    // A객체를 생성해서 A*에 담는다.
    A* pa2 = new A;

    // pa1을 C* 타입으로 형변환
    C* pc1 = dynamic_cast<C*>(pa1);         // 성공

    // pa2를 C* 타입으로 형변환
    // C* pc2 = dynamic_cast<C*><pa2);         // 실패

    try
    {
        //*pa2를 C&타입으로 형변환
        C& rc1 = dynamic_cast<C&>(*pa2);    // 실패: bad_case 발생
    }
    catch(std::bad_cast& e)
    {

    }
    return 0;
}