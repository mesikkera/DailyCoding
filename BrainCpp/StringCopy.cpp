#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // 원본 문자열
    char src[] = "Hello-World";

    // 원본 문자열의 길이
    int len = strlen(src);

    // 새 문자열이 담길 메모리 할당
    char* dest = new char [len + 1];

    // 문자열 복사
    strcpy(dest, src);

    // 결과 출력
    cout << "src = " << src << endl;
    cout << "dest = " << dest << endl;

    // 메모리 해제
    delete [] dest;
    dest = NULL;

    return 0;
}