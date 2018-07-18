#include <iostream>

using namespace std;

int main()
{
    // 정수 4개를 담는 2차원 배열. 
    // {1, 2, 3, 0}으로 초기화
    int data1[2][2] = {1, 2, 3};

    // 정수 6개를 담는 2차원 배열. 
    // {1, 0, 0, 0, 0, 0}으로 초기화
    int data2[2][3] = { { 1, } };

    cout << "data1[0][0] = " << data1[0][0] << endl;
    cout << "data1[0][1] = " << data1[0][1] << endl;
    cout << "data1[1][0] = " << data1[1][0] << endl;
    cout << "data1[1][2] = " << data1[1][1] << endl;

    cout << endl;
    cout << "data2[0][0] = " << data2[0][0] << endl;
    cout << "data2[0][1] = " << data2[0][1] + 1 << endl;
    cout << "data2[0][2] = " << data2[0][2] + 2 << endl;
    cout << "data2[1][0] = " << data2[1][0] + 3 << endl;
    cout << "data2[1][1] = " << data2[1][1] + 4 << endl;
    cout << "data2[1][2] = " << data2[1][2] + 5 << endl;

    return 0;
}