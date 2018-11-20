#include <iostream>

using namespace std;

class Animal;

class AnimalDelegate{
public:
    virtual void onSound(Animal* pSender)=0;
    virtual void onWalk(Animal* pSender)=0;
};

class Animal{
private:
    AnimalDelegate* delegate;

public:

    Animal(){
        this->delegate = NULL;
    }

    void setDelegate(AnimalDelegate* delegate){
        this->delegate = delegate;
    }

    void sound(){
        if(this->delegate){
            this->delegate->onSound(this);
        }
    }

    void walk(){
        if(this->delegate){
            this->delegate->onWalk(this);
        }
    }
};



//개 : Delegate를 내부에 직접 구현
class Dog:public Animal, public AnimalDelegate{
public:
    Dog(){
        this->setDelegate(this);
    }

    void onSound(Animal* pSender){
        cout << "Dog: 멍멍!" << endl;
    }

    void onWalk(Animal* pSender){
        cout << "Dog: 개가 걷는다" << endl;
    }
};

//고양이 Delegate
class CatDelegate:public AnimalDelegate{
public:
    void onSound(Animal* pSender){
        cout << "Cat: 야옹~" << endl;
    }

    void onWalk(Animal* pSender){
        cout << "Cat: 고양이가 걷는다" << endl;
    }
};

//고양이
class Cat:public Animal{};


int main(){

    Dog dog;
    Cat cat;

    dog.sound();
    dog.walk();
    
    CatDelegate cdel;

    cat.setDelegate(&cdel);
    cat.sound();
    cat.walk();
    
    getchar();

    return 0;
}