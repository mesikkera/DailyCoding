#include <iostream>
#include <string>
using namespace std;

// 애완 동물 클래스
class Pet 
{
public:
    // 오버로드된 두 개이 멤버 함수 Eat()
    void Eat();
    void Eat(const string& it);

    string name;
};

void Pet::Eat()
{
    cout << name << " says, 'Where is the food?'\n";
}

void Pet::Eat(const string& it)
{
    cout << name << " says, 'I like " << it << ".'\n";
}

// 강아지 클래스
class Dog : public Pet 
{
    // 애완 동물 클래스를 상속받아 강아지 클래스 정의 
    // 현재는 아무런 멤버도 없다.

    // 인자가 없는 Eat() 함수를 오버라이딩
public:
    void Eat();

    // Dog 클래스에 인자가 있는 생성자 추가
    Dog(int n);

};

Dog::Dog(int n)
{
    // 하는 일 없음.
}
void Dog::Eat()
{
    cout << name << " says, 'Growl~'\n";
}

int main()
{
    // 강아지 생성
    Dog dog1;
    dog1.name = "Patrasche";

    // 두 가지 Eat() 함수 호출
    dog1.Eat();
    dog1.Eat( "milk" );

    return 0;
}