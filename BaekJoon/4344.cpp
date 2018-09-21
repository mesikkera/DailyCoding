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
    int c = 0;
    int numbers = 0;
    int score = 0;
    double average = 0.0;
    double result[1000] = {};
    
    cout << fixed;
    cout << setprecision(3);
    
    // 테스트 케이스 입력
    cin >> c;

    for(int i = 0; i < c; i++) {
        cin >> numbers;
        int sum = 0;
        int* scores = new int[numbers];
        
        for (int j = 0; j < numbers; j++) {
            cin >> scores[i];
            sum += scores[i];
        }

        average = (double)sum / (double)numbers;

        int count = 0; 
        for (int z = 0; z < numbers; z++) {
            if( scores[z] > average)
                count++;
        }    
        int over_average = 0;
        over_average = ( count / numbers ) * 100;
        
        result[i] = over_average;        
    }
}

#include 

using namespace std;

int main(void)
{
	int C,C1;
	
	int m[100][1000];
	float aver[1000];
	float total[1000] = { 0, };
	float cnt[1000];
	cin >> C;
	cout << fixed;
	cout.precision(3);

	for (int i = 0; i < C; ++i) {
		float count = 0.0;
		cin >> C1;
		for (int j = 0; j < C1; ++j) {
			cin >> m[i][j];
			total[i] += m[i][j];
		}
		aver[i] = total[i] / (float)C1;
		for (int j = 0; j < C1; ++j)
			if (m[i][j] > aver[i])
				count++;
		cnt[i] = count/C1*100;
	}

	for (int i = 0; i < C; ++i)
		cout << cnt[i] << "%" << endl;


	return 0;
}

