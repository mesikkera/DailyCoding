#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string test_string1 = "REPUBLIC OF KOREA";
    string test_string2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

    // transform 함수 인자 전달 순서
    // 01. 복사할 문자열의 시작점
    // 02. 복사할 문자열의 종료점
    // 03. 복사될 문자열의 시작점(다른 문자열 변수에 대입할 수 있음.)
    // 04. 대문자로 변환하려면 toupper, 소문자로 변환하려면 tolower 사용
    transform(test_string1.begin(), test_string1.end(), test_string1.begin(), ::tolower);
    transform(test_string2.begin(), test_string2.end(), test_string2.begin(), ::toupper);

    // 하나의 문자를 변환할 때는 toupper, tolower 함수 호출
    // 반환값: 대문자 또는 소문자로 변환한 결과 값.
    char lower_ch = 'g';
    char upper_ch = 'B';

    lower_ch = toupper(lower_ch);
    upper_ch = tolower(upper_ch);

    cout << "String to Upper Case: " << test_string2 << endl;
    cout << "String to Lower Case: " << test_string1 << endl;
    cout << "Character to Upper Case: " << lower_ch << endl;
    cout << "Character to Lower Case: " << upper_ch << endl;

    return 0;
}