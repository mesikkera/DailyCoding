#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence = "I hate coding.";
    cout << sentence << endl;

    // erase �Լ�: ���ڿ� �Ϻ� ����
    // erase(arg1, arg2)
    // arg1 : ������ ������ ���� �ε���
    // arg2 : ������ ������ ����
    sentence.erase(0, 7);
    cout << "I like " << sentence << endl;

    return 0;
}