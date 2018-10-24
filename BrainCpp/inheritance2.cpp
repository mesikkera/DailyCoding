#include <iostream>
using namespace std;

class Person 
{
private:
    int agePrivate;
protected:
    int ageProtected;
public:
    int agePublic;
    Person(int age) : agePrivate(age), ageProtected(age), agePublic(age)
    {
    };
    ~Person()
    {
    }
};

class Chulsoo : public Person
{
private:
    int numOfBooks;
public:
    Chulsoo(int age, int numOfBooks) : Person(age), numOfBooks(numOfBooks)
    {
    }
    ~Chulsoo()
    {
    }
    void introduce()
    {
        cout << "ageProtected: " << ageProtected << endl;
        cout << "agePublic: " << agePublic << endl;
    }
};

int main(void)
{
    Chulsoo chulsoo(32, 3);
    chulsoo.introduce();
    return 0;
}