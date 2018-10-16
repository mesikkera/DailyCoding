//
//  Contact.h
//  Contact
//
//  Created by mesikkera on 16/10/2018.
//  Copyright © 2018 mesikkera. All rights reserved.
//

#ifndef Contact_h
#define Contact_h

#include <iostream>
#include "PersonalContact.h"

class Contact
{
private:
    PersonalContact contactInfo[100];
    int numberOfContact;
    
public:
    // 생성자: 멤버 초기화를 위해 생성
    Contact();
    
    // 연락처 정보 입력
    void inputContact(char *name, char *phoneNumer=NULL, char *email=NULL, char *address=NULL);
    
    // 연락처 전체 목록 조회
    void printContactList();
    
    // 연락처 상세 조회: index
    void printContact(int index);
    
    // 연락처 상세 조회: 이름 (함수 오버로딩)
    void printContact(char *inName);
    
    // 연락처 수정
    void editContactByIndex(int index, char *name, char *phoneNumber=NULL, char *email=NULL, char *address=NULL);
    
    // 연락처 복사
    void copyContact(int index);
    
    // 연락처 제거
    void removeContactByIndex(int index);
};

#endif /* Contact_h */
