#include <iostream>
using namespace std;

// first 네임스페이스 정의
namespace first 
{
    int value = 1;
}

// second 네임스페이스 정의
namespace second 
{
    int value = 2;
}

int main()
{
    int i = 0;
    cout << first::value << endl;
    cout << second::value << endl;
    return 0;
}