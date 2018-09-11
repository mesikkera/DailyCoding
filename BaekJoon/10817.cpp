/*
문제
세 정수 A, B, C가 주어진다. 이 때, 두 번째로 큰 정수를 출력하는 프로그램을 작성하시오. 

입력
첫째 줄에 세 정수 A, B, C가 공백으로 구분되어 주어진다. (1 ≤ A, B, C ≤ 100)

출력
두 번째로 큰 정수를 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    vector<int> v;

    v.push_back(x);
    v.push_back(y);
    v.push_back(z);
    sort(v.begin(), v.end());
    cout << v[1] << "\n";
    
    return 0;
}