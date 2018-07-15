#include <iostream>
#include <string>

using namespace std;

int main()
{
    string king = "Josun Sejong";
    string favorite1 = "meat";
    string favorite2 = "night shift";

    string king_info = "";

    // += 이란 축약된 형태로 하나의 문자열에 다른 문자열을 합친다.
    // append는 추가한다는 의미로, +=과 똑같은 의미.
    king_info += king;
    king_info += " likes ";
    king_info += favorite1;
    king_info.append(" and ");
    king_info.append(favorite2);
    king_info.append(". ");

    cout << king_info << endl;

    return 0;
}