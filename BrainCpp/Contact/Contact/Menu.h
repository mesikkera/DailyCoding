//
//  Menu.h
//  Contact
//
//  Created by mesikkera on 16/10/2018.
//  Copyright © 2018 mesikkera. All rights reserved.
//

#ifndef Menu_h
#define Menu_h

#include <iostream>

class Menu
{
private:
    char topMenu[3][32];                    // 최상위 메뉴 정보
    char ownerMenu[4][32];                  // 소유자 메뉴 정보
    char contactMenu[7][32];                // 연락처 메뉴 정보
    int menuType;                           // 0. top menu, 1. owner menu, 2. contact menu
    
public:
    // 생성자
    Menu();
    
    // 현재 메뉴 선택 상태를 통해 메뉴 목록 출력
    void showMenu();
    
    // 첫번째 단계 메뉴 선택
    void setMenuSelection(int selection);
    
    // 선택한 메뉴 실행
    int execution();
};
#endif /* Menu_h */
