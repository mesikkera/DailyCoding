#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int number = 4;

    vector<int> data{4, 1, 3, 5, 2, 3, 1, 7};

    vector<int>::iterator result1 = find_if(data.begin(), data.end(), [number](int i) { return i > number;});

    cout << "4보다 큰 첫 번째 정수: " << *result1 << endl;

    auto result2 = count_if(data.begin(), data.end(), [number](int i) { return i > number;});

    cout << "4보다 큰 정수의 개수: " << result2 << endl;

    return 0;
}