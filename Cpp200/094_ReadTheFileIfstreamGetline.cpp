#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream file;
    // ifstream::in --> 열기 모드
    file.open("093.txt", ifstream::in);

    string line;

    // geline 함수: 한 줄씩 읽어 line 변수에 저장.
    while(getline(file, line))
        cout << line << endl;

    file.close();

    return 0;
}