/*
아스키 코드 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	13673	11108	10159	82.870%
문제
알파벳 소문자, 대문자, 숫자 0-9중 하나가 주어졌을 때, 주어진 글자의 아스키 코드값을 출력하는 프로그램을 작성하시오.

입력
알파벳 소문자, 대문자, 숫자 0-9 중 하나가 첫째 줄에 주어진다.

출력
입력으로 주어진 글자의 아스키 코드 값을 출력한다.
*/
#include <iostream>
using namespace std;

int main()
{
    char  Character;
    cin >> Character;
    cout << (int)Character << "\n";
    return 0;
}