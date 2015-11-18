#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str = "Writeinfile";
	ofstream ofs("file.txt");
	ofs << str;
	ofs.close();
	ifstream ifs("file.txt");
	ifs >> str;
	cout << str << endl;
	ifs.close();
}