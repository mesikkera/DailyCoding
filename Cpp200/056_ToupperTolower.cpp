#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string test_string1 = "REPUBLIC OF KOREA";
    string test_string2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

    // transform �Լ� ���� ���� ����
    // 01. ������ ���ڿ��� ������
    // 02. ������ ���ڿ��� ������
    // 03. ����� ���ڿ��� ������(�ٸ� ���ڿ� ������ ������ �� ����.)
    // 04. �빮�ڷ� ��ȯ�Ϸ��� toupper, �ҹ��ڷ� ��ȯ�Ϸ��� tolower ���
    transform(test_string1.begin(), test_string1.end(), test_string1.begin(), ::tolower);
    transform(test_string2.begin(), test_string2.end(), test_string2.begin(), ::toupper);

    // �ϳ��� ���ڸ� ��ȯ�� ���� toupper, tolower �Լ� ȣ��
    // ��ȯ��: �빮�� �Ǵ� �ҹ��ڷ� ��ȯ�� ��� ��.
    char lower_ch = 'g';
    char upper_ch = 'B';

    lower_ch = toupper(lower_ch);
    upper_ch = tolower(upper_ch);

    cout << "String to Upper Case: " << test_string2 << endl;
    cout << "String to Lower Case: " << test_string1 << endl;
    cout << "Character to Upper Case: " << lower_ch << endl;
    cout << "Character to Lower Case: " << upper_ch << endl;

    return 0;
}