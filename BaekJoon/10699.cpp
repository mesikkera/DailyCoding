/*
오늘 날짜 스페셜 저지
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	4898	2987	2741	64.631%
문제
서울의 오늘 날짜를 출력하는 프로그램을 작성하시오.

입력
입력은 없다.

출력
서울의 오늘 날짜를 "YYYY-MM-DD" 형식으로 출력한다.

예제 입력 1 
예제 출력 1 
2015-01-24
힌트
채점 서버는 시간대(Timezone)는 UTC+0 이다.

다음은 채점 서버에서 KST 시간으로 2018년 3월 21일 오후 2시 7분 38초에 date 명령어를 실행시킨 결과이다.

Wed Mar 21 05:07:38 UTC 2018
*/
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

// 현재시간을 string type으로 return하는 함수
const string currentDate() {
    time_t     now = time(0); //현재 시간을 time_t 타입으로 저장
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct); // YYYY-MM-DD 형태의 스트링

    return buf;
}

int main() {
    cout << currentDate() << endl;
    return 0;
}