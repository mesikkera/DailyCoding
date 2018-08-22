#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // 최대 3명의 성적 보관
    int S1_No, S2_No, S3_No;                        // 학번
    int S1_Kor, S2_Kor, S3_Kor;                     // 국어점수
    int S1_Eng, S2_Eng, S3_Eng;                     // 영어점수
    int S1_Math, S2_Math, S3_Math;                  // 수학점수
    float S1_Ave, S2_Ave, S3_Ave;                   // 평균점수
    float TotalAve = 0.0f;                          // 전체평균
    int NumberOfStudent = 0;                        // 현재까지 입력된 학생수
    // 계속해서 메뉴를 보여준다.
    while(1)
    {
        // 메뉴 보여 주기
        cout << endl << "===== 메뉴 =====" << endl;
        cout << "1. 학생 성적 추가" << endl;
        cout << "2. 전체 성적 보기" << endl;
        cout << "Q. 프로그램 종료" << endl;
        cout << "==============" << endl;

        // 작업 입력 받기
        char select;
        cin >> select;

        // 선택된 값에 따라서 처리
        switch(select)
        {
        case '1':
            // 학생 성적 축가
            {
                // 3명 모두 입력되었으면 무시
                if(NumberOfStudent == 3)
                {
                    cout << endl << "더 이상 입력할 수 없습니다." << endl;
                    break;
                }

                // 국어, 영어, 수학 점수를 입력 받는다.
                int Kor, Eng, Math;

                cout << "국어, 영어, 수학 점수를 입력하세요 : ";
                cin >> Kor >> Eng >> Math;

                // 평균 계산
                float Ave = float(Kor + Eng + Math) / 3.0f;

                // 알맞는 변수에 입력된 값을 넣는다.
                if (NumberOfStudent == 0)
                {
                    // 개인 정보
                    S1_No = NumberOfStudent + 1;
                    S1_Kor = Kor;
                    S1_Eng = Eng;
                    S1_Math = Math;
                    S1_Ave = Ave;

                    // 전체 평균
                    TotalAve = S1_Ave;
                }
                else if (NumberOfStudent == 1)
                {
                    // 개인 정보
                    S2_No = NumberOfStudent + 1;
                    S2_Kor = Kor;
                    S2_Eng = Eng;
                    S2_Math = Math;
                    S2_Ave = Ave;

                    // 전체 평균
                    TotalAve = (S1_Ave + S2_Ave) / 2;
                }
                else 
                {
                    S3_No = NumberOfStudent + 1;
                    S3_Kor = Kor;
                    S3_Eng = Eng;
                    S3_Math = Math;
                    S3_Ave = Ave;

                    // 전체 평균
                    TotalAve = (S1_Ave + S2_Ave + S3_Ave) / 3;
                }

                // 입력 받은 학생 수를 증가시킨다.
                NumberOfStudent++;

                // 작업의 성공을 알림
                cout << endl << "학생 성적이 올바르게 입력되었습니다." << endl;
            }

        case '2':
            // 전체 성적 보기
            {
                // 실수 출력시 소수점 이하 2자리만 표시
                cout.precision(2);
                cout << fixed;

                // 타이틀 부분 출력
                cout << endl << "전체 성적 보기" << endl;
                cout << "학번 국어 영어 수학 평균" << endl;

                // 입력된 학생 수 만큼 반복
                for (int i = 0; i < NumberOfStudent; ++i)
                {
                    // 알맞은 학생의 정보를 출력한다.
                    if (i == 0)
                    {
                        cout << S1_No << setw(7) << S1_Kor << setw(5) << S1_Eng << setw(5) << S1_Math << setw(7) << S1_Ave << endl;
                    }
                    else if (i == 1)
                    {
                        cout << S2_No << setw(7) << S2_Kor << setw(5) << S2_Eng << setw(5) << S2_Math << setw(7) << S2_Ave << endl;
                    }
                    else 
                    {
                        cout << S3_No << setw(7) << S3_Kor << setw(5) << S3_Eng << setw(5) << S3_Math << setw(7) << S3_Ave << endl;
                    }
                }
            }
            
            // 전체 평균을 출력
            cout << endl << "전체 평균 = " << TotalAve << endl;

            break;

        case 'Q':
        case 'q':
            // 종료
            cout << "\n프로그램을 종료합니다." << endl;
            break;

        default:
            // 그 외의 선택
            cout << "\n올바른 값을 입력해주세요.\n";
            break;
        }

    }
    return 0;
}