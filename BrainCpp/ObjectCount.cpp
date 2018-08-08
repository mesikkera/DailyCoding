#include <iostream>
#include <string>
using namespace std;

// 학생 클래스
class Student 
{
public:
    string name;                // 이름
    int sNo;                    // 학번

    // 생성자, 소멸자
    Student(const string& name_arg, int stdNumber);
    ~Student();

public:
    // 정적 멤버들
    static int student_count;
    static void PrintStudentCount();
};

// 정적 멤버 변수
int Student::student_count = 0;

// 정적 멤버 함수
void Student::PrintStudentCount()
{
    cout << "Student 객체 수 = " << student_count << endl;
}

Student::Student(const string& name_arg, int stdNumber)
{
    // 학생 객체의 수를 증가시킨다.
    student_count++;

    name = name_arg;
    sNo = stdNumber;
}

Student::~Student()
{
    // 학생 객체의 수를 감소시킨다.
    student_count--;
}

void Func()
{
    // 객체 생성
    Student std1("Bill", 342);
    Student std2("James", 214);

    Student::PrintStudentCount();
}

int main()
{
    Student::PrintStudentCount();

    // 객체 생성
    Student std("Jeffrey", 123);

    Student::PrintStudentCount();

    // Func() 함수 호출
    Func();

    Student::PrintStudentCount();

    return 0;
}