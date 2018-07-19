#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // 파일 오픈 => 파일 생략시 ifstream::in으로 설정
    ifstream ifs("lorem ipsum.txt");

    stringstream ss;

    ss << ifs.rdbuf();
    ifs.close();

    string read = "";

    cout << "== !ss.eof ==" << endl;
    while(!ss.eof())
    {
        ss >> read;
        cout << read << " ";
    }

    cout << endl << "== !ss.str() ==" << endl;
    read = ss.str();
    cout << endl << read << endl;

    return 0;
}