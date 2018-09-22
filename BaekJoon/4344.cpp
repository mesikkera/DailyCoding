/* 평균은 넘겠지
문제
대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.

입력
첫째 줄에는 테스트 케이스의 개수 C가 주어진다.

둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 
이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

출력
각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int TestCase = 0;
    int StudentNumbers = 0;
    int score = 0;
    double average = 0.0;
    
    // 테스트 케이스 입력
    cin >> TestCase;

    // 각 테스트 케이스별 학생 수와 점수를 입력받아
    // 평균을 구하고, 평균을 넘는 학생 수의 %를 구하고 출력한다.
    for(int i = 0; i < TestCase; i++) {
        cin >> StudentNumbers;
        int TotalScoreSum = 0;            // 학생 점수의 총합
        
        // 동적 할당을 통한 배열 생성 (학생 점수 입력)
        int* Scores = new int[StudentNumbers];
        
        // 학생 점수 총합
        for (int j = 0; j < StudentNumbers; j++) {
            cin >> Scores[j];
            TotalScoreSum += Scores[j];
        }
        
        // 평균 점수
        average = (double)TotalScoreSum / (double)StudentNumbers;
        
        // 평균을 넘는 학생 수 
        int OverAverageCount = 0; 
        for (int z = 0; z < StudentNumbers; z++) {
            if( Scores[z] > average)
                OverAverageCount+=1;
        }    
        
        // 평균을 넘는 학생의 퍼센트
        double OverAveragePercentage = 0.0;
        OverAveragePercentage = ( (double)OverAverageCount / (double)StudentNumbers ) * 100;
        
        cout << fixed;
        cout << setprecision(3);
        cout << OverAveragePercentage << "\%" << endl;        
    }
}