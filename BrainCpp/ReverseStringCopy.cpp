#include <iostream>
using namespace std;

// 문자열을 뒤집어서 복스해주는 함수
char* ReverseString(const char* src, int len)
{
    // 새로운 문자열을 보관할 메모리 할당
    char* reverse = new char [len+1];

    // 문자열을 역순으로 복사한다.
    for (int i = 0; i < len; ++i)
        reverse[i] = src[len - i - 1];

    // 새 문자열의 끝에 NULL을 넣어준다.
    reverse[len] = NULL;

    return reverse;
}

int main()
{
    // 문자열을 만든다.
    char original[] = "DOREMIPASOLRASIDO";

    // 함수 호출
    char* copy = ReverseString(original, 16);

    // 두 문자열 출력
    cout << "Original = " << original << endl;
    cout << "Reverse = " << copy << endl;

    // 새 문자열의 메모리 해제
    delete[] copy;
    copy = NULL;

    return 0;
}