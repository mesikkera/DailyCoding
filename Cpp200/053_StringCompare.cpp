#include <iostream>

using namespace std;

int main()
{
    string string_compare1 = "South Korea";
    string string_compare2 = "North Korea";

    // ���ڿ� ��: compare()
    // ���� ���� ���ٸ� 0 ����
    // ���� ���� �ٸ��� -1 ����
    if (string_compare1.compare(string_compare2) == 0)
        cout << "Same String!" << endl;
    else
        cout << "Defferent String!" << endl;

    return 0;
}