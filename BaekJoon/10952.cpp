/*
문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다.

각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)

A와 B가 모두 0인 경우에 프로그램을 종료한다.
*/
#include <iostream>
using namespace std;

int main()
{
    int number1 = 0, number2 = 0;

    while (cin >> number1 >> number2) {
        if(number1 == 0 && number2 == 0)
        {
            break;
        }
        
        cout << number1 + number2 << "\n";
    }
    return 0;
}