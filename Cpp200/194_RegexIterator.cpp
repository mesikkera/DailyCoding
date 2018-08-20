#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    string str = "Jolbon Buyeo was the predecessor to Goguryeo, and in 538, Baekje renamed itself Nambuyeo (South Buyeo)";

    regex re("([A-Za-z]+)");

    auto start = sregex_iterator(str.begin(), str.end(), re);
    auto end = sregex_iterator();

    cout << " == 단어 개수 : " << distance(start, end) << " == " << endl;

    for (sregex_iterator i = start; i != end; ++i)
        cout << i->position() << ", " << i->str() << endl;

    return 0;
}