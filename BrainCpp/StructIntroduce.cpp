#include <iostream>
using namespace std;

#define NAME_LEN 20
#define SEX_LEN 10
#define JOB_LEN 10
#define CHARACTER_LEN 20

struct Chulsoo 
{
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    bool marriageStatus;

    void introduce()
    {
        cout << "이름: " << name << endl;
        cout << "성별: " << sex << endl;
        cout << "직업: " << job << endl;
        cout << "성격: " << character << endl;
        cout << "나이: " << age << endl;
        cout << "결혼여부: " << (marriageStatus ? "YES" : "NO") << endl;
    }

    void eat(char * food)
    {
        cout << "철수는 " << food << "를 먹는다." << endl;
    }

    void sleep()
    {
        cout << "철수는 잔다." << endl;
    }

    void drive(char * destination)
    {
        cout << "철수는 " << destination << "으로 운전한다." << endl;
    }

    void write()
    {
        cout << "철수는 책을 쓴다." << endl;
    }

    void read()
    {
        cout << "철수는 책을 읽는다." << endl;
    }
};

struct Younghee 
{
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    bool marriageStatus;

    void introduce()
    {
        cout << "이름: " << name << endl;
        cout << "성별: " << sex << endl;
        cout << "직업: " << job << endl;
        cout << "성격: " << character << endl;
        cout << "나이: " << age << endl;
        cout << "결혼여부: " << (marriageStatus ? "YES" : "NO") << endl;
    }

    void eat(char * food)
    {
        cout << "영희는 " << food << "를 먹는다." << endl;
    }

    void sleep()
    {
        cout << "영희는 잔다." << endl;
    }

    void shopping()
    {
        cout << "영희는 쇼핑을 한다." << endl;
    }
};

int main(void)
{
    Chulsoo chulsoo = {"철수", "남성", "작가", "diligent", 32, true};
    Younghee younghee = {"영희", "여성", "주부", "impatient", 32, true};

    chulsoo.drive("레스토랑");
    chulsoo.eat("스테이크");
    younghee.eat("스테이크");
    chulsoo.drive("집");
    younghee.sleep();
    chulsoo.write();
    chulsoo.read();
    chulsoo.sleep();
    cout << endl;
    chulsoo.introduce();
    cout << endl;
    younghee.introduce();

    return 0;
}