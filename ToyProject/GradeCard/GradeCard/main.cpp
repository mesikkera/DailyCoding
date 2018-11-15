//
//  main.cpp
//  GradeCard
//
//  Created by mesikkera on 12/11/2018.
//  Copyright © 2018 mesikkera. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    // 계속해서 메뉴를 보여준다.
    while(1) {
        // 메뉴 보여주기
        cout << "\n----- 메뉴 -----\n";
        cout << "1. 학생 성적 추가\n";
        cout << "2. 전체 성적 보기\n";
        cout << "-------------------";
        cout << "원하는 작업의 번호를 입력하세요 : ";
        
        // 작업 입력 받기
        char select;
        cin >> select;
        
        // 선택된 값에 따라서 처리
        switch(select) {
            case '1':
                // 학생 성적 추가
                cout << "\n학생 성적 추가가 선택되었습니다.";
        }
    }
    return 0;
}
