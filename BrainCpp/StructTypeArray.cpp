#include <iostream>
using namespace std;

// 학생 정보를 갖는 구조체
struct StudentInfo 
{
    char name[20];
    int stdNumber;
    float grade[2];
};

int main()
{
    // 구조체 배열 초기화
    StudentInfo stdInfos[5] = {
        {"Kim Chol-su", 2002121233, {3.2f, 3.5f}},
        {"Lee Chol-su", 2002121344, {4.0f, 3.8f}},
        {"Park Chol-su", 200321131, {1.7f, 2.0f}},
        {"Yang Chol-su", 200222289, {0.4f, 4.1f}},
        {"Yoon Chol-su", 199921444, {2.7f, 2.8f}}
    };

    // 정보 출력
    for(int i = 0; i < 5; i++)
    {
        cout << stdInfos[i].name << endl;
        cout << stdInfos[i].stdNumber << endl;
        cout << stdInfos[i].grade[0] << ", " << stdInfos[i].grade[1] << endl;
        cout << endl;
    }
    return 0;
}