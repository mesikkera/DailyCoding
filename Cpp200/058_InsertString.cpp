#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence = "I coding.";
    sentence.insert(2, "love ");
    cout << sentence << endl;

    sentence.insert(7, "or like ");
    cout << sentence << endl;

    return 0;
}