#include <iostream>
#include <string>

using namespace std;

void Func1(int &arg)
{
    cout << "Before Addition : " << arg << endl;
    arg += 10;
    cout << "After Addition : " << arg << endl;
}

void Func2(string &info)
{
    info += "2018";
}

int main()
{
    int year = 10;

    Func1(year);

    cout << "After Func1() : " << year << endl;

    string sentence = "test_string: " ;

    Func2(sentence);

    cout << sentence << endl;

    return 0;


}