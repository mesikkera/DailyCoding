#include <iostream>
#include <string>
#include <vector>

using namespace std;

int PointerFunc(vector<string> *info)
{
    if (info -> empty() == true)
        return 0;
    else
        return sizeof(info);
}

int main()
{
    vector<string> message;
    message.push_back("France win worldcup");
    message.push_back("Croatia");
    message.push_back("Belgium");
    message.push_back("England");

    cout << "������ ���� ũ�� : " << PointerFunc(&message) << endl;
    cout << "���� ���� ũ�� : " << sizeof(message) << endl;

    return 0;    
}