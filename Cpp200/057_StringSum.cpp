#include <iostream>
#include <string>

using namespace std;

int main()
{
    string king = "Josun Sejong";
    string favorite1 = "meat";
    string favorite2 = "night shift";

    string king_info = "";

    // += �̶� ���� ���·� �ϳ��� ���ڿ��� �ٸ� ���ڿ��� ��ģ��.
    // append�� �߰��Ѵٴ� �ǹ̷�, +=�� �Ȱ��� �ǹ�.
    king_info += king;
    king_info += " likes ";
    king_info += favorite1;
    king_info.append(" and ");
    king_info.append(favorite2);
    king_info.append(". ");

    cout << king_info << endl;

    return 0;
}