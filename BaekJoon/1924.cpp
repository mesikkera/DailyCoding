/* 2007년
문제
오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다. 참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.

출력
첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.
*/

#include <iostream>
using namespace std;

int main()
{
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    int x = 0;
    int y = 0;
    int week_day = 0;
    cin >> x >> y;
    
    // 입력한 월(x)의 직전 월(x-1)까지의 날짜의 총합 + 입력한 일(y) = 입력한 월과 일까지의 총 일 수
    // 총 일 수에서 7(요일의 수)로 나눈 나머지가 요일이 된다
    for (int i = 0; i < x -1; i++)
        y += month[i];
    week_day = y % 7;

    cout << day[week_day];
    
    return 0;
}