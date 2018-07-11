#include <iostream>

using namespace std;

int main()
{
    int x = 1;
    int y = 2;
    int z = 0;

    z = x > y ? x : y;

    cout << "x와 y중 더 큰 값은: " << z << endl;

    return 0;
}