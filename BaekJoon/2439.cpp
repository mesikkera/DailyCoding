/* 별찍기 - 2
문제
첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제

하지만, 오른쪽을 기준으로 정렬한 별 (예제 참고)을 출력하시오.
입력
첫째 줄에 N (1<=N<=100)이 주어진다.

출력
첫째 줄부터 N번째 줄 까지 차례대로 별을 출력한다.
*/
#include<iostream>
#include<cstdio>
using namespace std;

int main(void) {
    int number;
    cin >> number;
    
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            if (j < number - i - 1) 
                cout << " ";
            else
                cout << "*";
        }
        cout << endl;
    }
    return 0;
}