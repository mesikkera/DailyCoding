#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    auto result1 = min(1, 5);
    auto result2 = max('a', 'z');

    cout << result1 << ", " << result2 << endl;

    auto result3 = minmax({'a', 'n', 'z'});
    auto result4 = minmax({1, 2, 3});

    cout << result3.first << ", " << result3.second << endl;
    cout << result4.first << ", " << result4.second << endl;

    return 0;
}