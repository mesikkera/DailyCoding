/*
문제


연세대학교의 영문명은 YONSEI, 슬로건은 Leading the Way to the Future이다.

이를 출력하는 프로그램을 작성해보도록 하자.

입력
첫째 줄에 N이 주어진다. (N = 0 또는 1)

출력
N = 0일 경우: 연세대학교의 영문명을 출력한다.
N = 1일 경우: 연세대학교의 슬로건을 출력한다.
대소문자 구별에 주의하도록 하자.
*/
#include <iostream>
using namespace std;

int main()
{
    int n(0);
    cin >> n;
    if (n == 0)
        cout << "YONSEI";
    
    if (n == 1)
        cout << "Leading the Way to the Future";
    
    return 0;
}