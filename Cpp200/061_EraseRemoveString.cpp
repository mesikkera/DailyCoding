#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string sentence = "I like coding.";

    sentence.erase(remove(sentence.begin(), sentence.end(), ' '), sentence.end());

    cout << sentence << endl;

    return 0;
}