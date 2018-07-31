#include <iostream>
using namespace std;

void GCD_LCM(int a, int b, int* pgcd, int* plcm)
{
    // 유클리드 호제법
    int z;
    int x = a;
    int y = b;
    while(true)
    {
        z = x % y;
        if (0 == z)
            break;

        x = y;
        y = z;
    }

    // 결과 저장
    *pgcd = y;
    *plcm = a * b / *pgcd;
}

int main()
{
    // 28과 35dml 최대공약수와 최소공배수
    int gcd = 0;
    int lcm = 0;
    GCD_LCM(28, 35, &gcd, &lcm);

    // 결과 출력
    cout << "GCD = " << gcd << endl;
    cout << "LCM = " << lcm << endl;

    return 0;
}