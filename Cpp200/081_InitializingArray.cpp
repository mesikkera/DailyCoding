#include <iostream>

using namespace std;

int main()
{
    int data1[3] = {0, 1, 2};
    // {} 안에 정수 0과 쉼표를 하나 붙여서 초기화
    // 배열의 크기가 몇 개라도 모두 0으로 초기화
    // 0, => 0, 0, 0, 0 과 같은 의미
    // 2차원 배열이므로 {{}}를 2개 사용하여 2행을 모두 초기화
    int data2[2][2]{ {0, }, };
    int data3[2][2];

    cout << "== data1 ==" << endl;
    for (int i = 0; i < 3; i++)
        cout << "data1[" << i << "] = " << data1[i] << endl;

    cout << endl << "== data2 ==" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << "dat2[" << i << "][" << j << "] = " << data2[i][j] << endl;
    }

    cout << endl << "== data3 ==" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << "data3[" << i << "][" << j << "] = " << data3[i][j] << endl;
    }
    return 0;
}