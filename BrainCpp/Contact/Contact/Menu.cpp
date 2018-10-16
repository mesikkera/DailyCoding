//
//  Menu.cpp
//  Contact
//
//  Created by mesikkera on 16/10/2018.
//  Copyright © 2018 mesikkera. All rights reserved.
//

#include "Menu.h"
using namespace std;

// 최상위 메뉴 정보 설정
Menu::Menu()
{
    strlcpy(topMenu[0], "1. 소유자 관리 기능", 32);
    strlcpy(topMenu[1], "2. 연락처 정보 관리 기능", 32);
    strlcpy(topMenu[2], "3. 프로그램 종료", 32);
    
    strlcpy(ownerMenu[0], "1. 소유자 정보 입력", 32);
    strlcpy(ownerMenu[1], "2. 소유자 정보 조회", 32);
    strlcpy(ownerMenu[2], "3. 소유자 정보 수정", 32);
    strlcpy(ownerMenu[3], "4. 이전 메뉴로", 32);
    
    strlcpy(contactMenu[0], "1. 연락처 추가 입력", 32);
    strlcpy(contactMenu[1], "2. 연락처 목록 조회", 32);
    strlcpy(contactMenu[2], "3. 연락처 상세 조회", 32);
    strlcpy(contactMenu[3], "4. 개별 연락처 수정", 32);
    strlcpy(contactMenu[4], "5. 연락처 복사", 32);
    strlcpy(contactMenu[5], "6. 개별 연락처 제거", 32);
    strlcpy(contactMenu[6], "7. 이전 메뉴로", 32);
    
    // 메뉴 기본값 0 (최상위 메뉴)
    menuType = 0;
}

// 현재 메뉴 선택 상태를 통해 메뉴 목록 출력
void Menu::showMenu()
{
    if(menuType == 0)
    {
        cout << topMenu[0] << endl;
        cout << topMenu[1] << endl;
        cout << topMenu[2] << endl;
    }
    else if (menuType == 1)
    {
        cout << ownerMenu[0] << endl;
        cout << ownerMenu[1] << endl;
        cout << ownerMenu[2] << endl;
        cout << ownerMenu[3] << endl;
    }
    else if (menuType == 2)
    {
        cout << contactMenu[0] << endl;
        cout << contactMenu[1] << endl;
        cout << contactMenu[2] << endl;
        cout << contactMenu[3] << endl;
        cout << contactMenu[4] << endl;
        cout << contactMenu[5] << endl;
        cout << contactMenu[6] << endl;
    }
}

// 첫 번째 단계 메뉴 선택
void Menu::setMenuSelection(int selection)
{
    menuType = selection;
}

// 선택한 메뉴 실행
int Menu::execution()
{
    int selection;
    showMenu();
    cin >> selection;
    return selection;
}
