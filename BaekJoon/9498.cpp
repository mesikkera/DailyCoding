/*
문제
시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 시험 점수가 주어진다. 시험 점수는 0보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
시험 성적을 출력한다.
*/

#include <iostream>
using namespace std;

int main()
{
    int result;
    cin >> result;
    if (90 <= result && result <= 100)
        cout << "A" << "\n";
    else if(80 <= result && result < 90)
        cout << "B" << "\n";
    else if (70 <= result && result < 80)
        cout << "C" << "\n";
    else if (60 <= result && result < 70)
        cout << "D" << "\n";
    else
        cout << "F" << "\n";
    
    return 0;
}