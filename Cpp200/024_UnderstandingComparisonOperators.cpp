#include <string>
#include <iostream>

using namespace std;

int main()
{
    string publisher = "mesikkera";
    string language = "C++";

    int x = 10;
    int y = 10;

    // A == B : A�� B�� ������ ��
    // A != B : A�� B�� �ٸ��� ��
    // A > B : A�� B���� ũ�� ��
    // A < B : A�� B���� ������ ��
    // A >= B: A�� B���� ũ�ų� ������ ��
    // A <= B: A�� B���� �۰ų� ������ ��
    if (publisher != language)
        cout << "�� ������ ���� �ʽ��ϴ�." << endl;
    else
        cout << "�� ������ �����ϴ�." << endl;
    
    if (x >= y)
        cout << "x�� y���� ũ�ų� �����ϴ�." << endl;
    else
        cout << "x�� y���� ũ�ų� ���� �ʽ��ϴ�." << endl;
    
    if (x <= 20)
        cout << "x�� 20���� �۰ų� �����ϴ�." << endl;
    else
        cout << "x�� 20���� �۰ų� ���� �ʽ��ϴ�." << endl;

    return 0;
}