#include <iostream>

using namespace std;

// enum�� ��ҵ��� ������ ���� ���´�.
// �� ��Ҵ� ������ ����� ������ �ڵ����� 1�� Ŀ����.
// normal = 0 --> abnormal == 1
// disconnect = 100 --> close == 101
enum Status{
    normal = 0,
    abnormal, 
    disconnect = 100,
    close
};

int main()
{
    Status number = close;

    // enum �� ȣ��1
    if (number == Status::normal)
        cout << "Status : normal" << endl;
    // enum �� ȣ��2
    else if (number == abnormal)
        cout << "Status : abnormal" << endl;
    else if (number == 101)
        cout << "Status : disconnect" << endl;
    else
        cout << "Status : close" << endl;
    return 0;
}