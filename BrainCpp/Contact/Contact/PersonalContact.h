//
//  PersonalContact.h
//  Contact
//
//  Created by mesikkera on 16/10/2018.
//  Copyright © 2018 mesikkera. All rights reserved.
//

#ifndef PersonalContact_h
#define PersonalContact_h

#include <iostream>

class PersonalContact {
private:
    char name[20];                  // 이름
    char phoneNumber[13];           // 전화번호
    char email[30];                 // 이메일
    char address[50];               // 주소
    
public:
    // 기본 생성자
    PersonalContact(){}
    
    // 복사 생성자
    PersonalContact(PersonalContact &personal);
    
    // 연락처 입력
    void inputContact(char *inName, char *inPhoneNumber=NULL, char *inEmail=NULL, char *inAddress=NULL);
    
    // 연락처 조회
    void getContact(char *outName, char *outPhoneNumber, char *outEmail, char *outAddress);
    
    // 연락처 수정
    void editContact(char *inName, char *inPhoneNumber=NULL, char *inEmail=NULL, char *inAddress=NULL);
};

#endif /* PersonalContact_h */
