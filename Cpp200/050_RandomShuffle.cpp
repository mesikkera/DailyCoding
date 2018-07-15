#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>

using namespace std;

int main()
{
    string str1 = "1a2b3c4d5e6f7g8h9i";
    string str2 = "republic of korea";
    int data1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    srand(static_cast<unsigned int>(time(NULL)));

    // random_shuffle(str1.begin(), str1.end());
    // random_shuffle(str2.begin(), str2.end());

    cout << "== str1 == " << endl;
    for (auto i : str1)
        cout << i << ", ";

    cout << endl << "== str2 == " << endl;
    for (auto i : str2)
        cout << i << ", ";

    cout << endl << "== data1 ==" << endl;

    for (auto i : data1)
        cout << i << ", ";

    return 0;
}