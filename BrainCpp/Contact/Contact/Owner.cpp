//
//  Owner.cpp
//  Contact
//
//  Created by mesikkera on 15/10/2018.
//  Copyright © 2018 mesikkera. All rights reserved.
//

#include "Owner.h"

using namespace std;

// 소유자 정보 입력
void Owner::inputOwnerInfo(char *inName, char *inPhoneNumber, char *inEmail, char *inAddress, char *inTwitterAccount)
{
    if(inName != NULL)
        strlcpy(name, inName, 20);
    
    if(inPhoneNumber != NULL)
        strlcpy(phoneNumber, inPhoneNumber, 13);
    
    if (inEmail != NULL)
        strlcpy(email, inEmail, 30);
    
    if (inAddress != NULL)
        strlcpy(address, inAddress, 50);
    
    if (inTwitterAccount != NULL)
        strlcpy(twitterAccount, inTwitterAccount, 20);
}

// 소유자 정보 출력
void Owner::printOwnerInfo()
{
    cout << "소유자 이름: " << name << endl;
    cout << "소유자 전화번호: " << phoneNumber << endl;
    cout << "소유자 이메일: " << email << endl;
    cout << "소유자 주소: " << address << endl;
    cout << "소유자 트위터 계정: " << twitterAccount << endl;
}

// 소유자 정보 수정
void Owner::editOwnerInfo(char *inName, char *inPhoneNumber, char *inEmail, char *inAddress, char *inTwitterAccount)
{
    if (inName != NULL)
        strlcpy(name, inName, 20);
    
    if(inPhoneNumber != NULL)
        strlcpy(phoneNumber, inPhoneNumber, 13);
    
    if (inEmail != NULL)
        strlcpy(email, inEmail, 30);
    
    if (inAddress != NULL)
        strlcpy(address, inAddress, 50);
    
    if (inTwitterAccount != NULL)
        strlcpy(twitterAccount, inTwitterAccount, 20);
}
