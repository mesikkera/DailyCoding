//
//  Owner.h
//  Contact
//
//  Created by mesikkera on 15/10/2018.
//  Copyright © 2018 mesikkera. All rights reserved.
//

#ifndef Owner_h
#define Owner_h

#include <iostream>

class Owner {
private:
    char name[20];
    char phoneNumber[13];
    char email[30];
    char address[50];
    char twitterAccount[20];
    
public:
    // 소유자 정보 입력
    void inputOwnerInfo(char *inName, char *inPhoneNumber=NULL,
                        char *inEmail=NULL, char *inAddress=NULL, char *inTwitterAccount=NULL);
    
    // 소유자 정보 출력
    void printOwnerInfo();
    
    // 소유자 정보 수정
    void editOwnerInfo(char *inName, char *inPhoneNumber=NULL,
                       char *inEmail=NULL, char *inAddress=NULL, char *inTwitterAccount=NULL);
};

#endif /* Owner_h */
