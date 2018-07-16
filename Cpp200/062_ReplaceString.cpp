#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence = "I like coding.";
    string find_str = "coding";
    string replace_str = "driving";

    sentence.replace(sentence.find(find_str), find_str.length(), replace_str);

    cout << sentence << endl;

    return 0;
}