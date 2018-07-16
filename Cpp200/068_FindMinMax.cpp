#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    // auto: 반환형이 무엇인지 모를 때 사용ㅎ는 유용한 키워드
    auto result1 = min(1, 5);                                       // 최소값: 1
    auto result2 = max('a', 'z');                                   // 최대값: z

    cout << result1 << ", " << result2 << endl;                     // 출력: 1, z

    // a:97, n: 110, z:122
    auto result3 = minmax({'a', 'n', 'z'});                         // 최소값: a, 최대값: z
    auto result4 = minmax({1, 2, 3});                               // 최소값: 1, 최대값: 3

    // first: 최소값, second: 최대값
    cout << result3.first << ", " << result3.second << endl;        // 출력: a, z
    cout << result4.first << ", " << result4.second << endl;        // 출력: 1, 3

    return 0;
}