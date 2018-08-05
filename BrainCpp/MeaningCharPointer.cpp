#include <iostream>
using namespace std;

int main()
{
    char c = 'A';
    char s[] = "This is a string.";

    // cout 객체는 당연히 문자열이라고 생각하고,
    // NULL 문자가 나올 때까지 이어지는 모든 문자열을 출력하게 된다.
    cout << s << endl;
    cout << &s[0] << endl;

    // Char변수의 주소인데도 cout 객체는 NULL 문자가 나올 때까지 
    // 이어지는 모든 문자를 출력하게 되고, 그 결과 
    // 변수 C 뒤에 있는 메모리의 쓰레기 값을 출력
    cout << &c << endl;

    return 0;

}