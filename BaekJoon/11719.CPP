#include <iostream>  
#include <string>
using namespace std;

int main() {
    string word;
    int num = 100;

    while (num != 0)
    {
        getline(cin, word);
        cout << word << endl;
        num--;
    }
    return 0;
}