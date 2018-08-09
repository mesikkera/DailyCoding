#include <iostream>
#include <string>
using namespace std;

// 학생 클래스
class Student 
{
public:
    string name;                // 이름
    int sNo;                    // 학번

    void Print();

private:
    // 생성자
    // 생성자가 private인 경우에도 정적 멤버 함수에서는 객체를 생성할 수 있다.
    // 객체를 동적으로 생성해서 그 주소를 반환해야 한다.
    Student (const string& name_arg, int stdNumber);

public:
    // 정적 멤버
    static int studentNumber;
    static Student* CreateStudent(const string& name_arg);
};

// 정적 멤버 초기화
int Student::studentNumber = 0;

Student* Student::CreateStudent(const string& name_arg)
{
    // 학생 객체 생성
    Student* p = new Student(name_arg, studentNumber++);

    // 새로 생성된 학생 객체 반환
    return p;
}

Student::Student(const string& name_arg, int stdNumber)
{
    name = name_arg;
    sNo = stdNumber;
}

void Student::Print()
{
    cout << "{ Name = " << name << ", Std. Num. = " << sNo << " }\n";
}

int main()
{
    // 학생 객체 3개 생성
    Student* p1, * p2, * p3;
    p1 = Student::CreateStudent( "손흥민" );
    p2 = Student::CreateStudent( "오반석" );
    p3 = Student::CreateStudent( "조현우" );
    // 학생 정보 출력
    p1 -> Print();
    p2 -> Print();
    p3 -> Print();

    // 동적 생성 객체의 해제
    delete p1;
    delete p2;
    delete p3;
    p1 = p2 = p3 = 0;

    return 0;
}