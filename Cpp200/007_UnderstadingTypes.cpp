#include <iostream>
// 문자열 자료형인 string을 사용하기 위해 인클루드
#include <string>

using namespace std;

int main()
{
    char character = 'C';
    int integer = 100;
    double precision = 3.14159;
    bool is_true = true;
    string word = "Hello World";

    cout << "char: " << character << endl;
    cout << "int: " << integer << endl;
    cout << "double: " << precision << endl;
    cout << "bool: " << is_true << endl;
    cout << "string: " << word << endl;

    return 0;
}