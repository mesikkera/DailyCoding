#include <iostream>

using namespace std;

void Func(int arg)
{
    cout << "Before Addition : " << arg << endl;
    arg += 10;
    cout << "After Addition : " << arg << endl;
}

int main()
{
    int year = 10;
    
    // Call by Value�� ���ڷ� �Ѿ�� ���� ���������� �����ؼ� ���.
    // year ������ ���� 10�� ���ϴ� ���� �ƴ϶� 
    // ���������� ������ ���� 10�� ���� ��.
    // ���� year ������ ���� ������ ����.
    Func(year);

    cout << "After Call By Value : " << year << endl;

    return 0;
}