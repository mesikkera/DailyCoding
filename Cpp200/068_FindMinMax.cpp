#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    // auto: ��ȯ���� �������� �� �� ��뤾�� ������ Ű����
    auto result1 = min(1, 5);                                       // �ּҰ�: 1
    auto result2 = max('a', 'z');                                   // �ִ밪: z

    cout << result1 << ", " << result2 << endl;                     // ���: 1, z

    // a:97, n: 110, z:122
    auto result3 = minmax({'a', 'n', 'z'});                         // �ּҰ�: a, �ִ밪: z
    auto result4 = minmax({1, 2, 3});                               // �ּҰ�: 1, �ִ밪: 3

    // first: �ּҰ�, second: �ִ밪
    cout << result3.first << ", " << result3.second << endl;        // ���: a, z
    cout << result4.first << ", " << result4.second << endl;        // ���: 1, 3

    return 0;
}