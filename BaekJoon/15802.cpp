/*
문제
이 일이 끝나면 인류의 절반은 살아남을 것이다.

타노스가 당신 앞에 나타났다.

당신은 살아남을 수 있을까?

입력
이 문제는 입력이 주어지지 않는다.

출력
당신이 살아남는다면 1을, 살아남지 못한다면 0을 출력한다.
*/
#include <iostream>
using namespace std;

int main()
{
    string name;
    cin >> name;
    if ( name == "ironman")
        cout << "1" << "\n";
    else 
        cout << "0" << "\n";
    return 0;
}