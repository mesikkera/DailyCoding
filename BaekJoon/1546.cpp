/* 평균
문제
세준이는 기말고사를 망쳤다. 세준이는 점수를 조작해서 집에 가져가기로 했다. 
일단 세준이는 자기 점수 중에 최댓값을 골랐다. 이 값을 M이라고 한다. 
그리고 나서 모든 점수를 점수/M*100으로 고쳤다.

예를 들어, 세준이의 최고점이 70이고, 
수학점수가 50이었으면 수학점수는 50/70*100이 되어 71.43점이 된다.

세준이의 성적을 위의 방법대로 새로 계산했을 때, 새로운 평균을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 시험 본 과목의 개수 N이 주어진다. 이 값은 1000보다 작거나 같다. 둘째 줄에 세준이의 현재 성적이 주어진다. 이 값은 100보다 작거나 같은 음이 아닌 정수이고, 적어도 하나의 값은 0보다 크다.

출력
첫째 줄에 새로운 평균을 출력한다. 정답과의 절대/상대 오차는 10-2까지 허용한다.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int num = 0;
    double score = 0;
    double max_score = 0;
    double sum = 0.0;
 
    // 시험 과목 수 입력
    cin >> num;
    double* arr = new double[num];

    // 과목별 성적 입력
    for(int i = 0; i < num; i++) {
        cin >> arr[i];
        if (arr[i] > max_score)
            max_score = arr[i];
    }

    // 상향된 과목의 점수 
    for(int i = 0; i < num; i++) {
        sum += (arr[i] / max_score) * 100;
    }
    cout << std::fixed;
    cout << std::setprecision(2);
    cout << (sum/num);

    delete [] arr;
    return 0;
}