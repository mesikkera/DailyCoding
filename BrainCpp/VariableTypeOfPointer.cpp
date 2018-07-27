#include <iostream>
using namespace std;

int main()
{
    // int 타입
    int i = 300;
    int* pi = &i;

    // char 타입
    char c = 'C';
    char* pc = &c;

    // float 타입
    float f = 700.5f;
    float* pf = &f;

    // short int 타입
    short int s = 456;
    short int* ps = &s;
    cout << "ps주소: " << ps << endl;
}