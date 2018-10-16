//
//  PersonalContact.cpp
//  Contact
//
//  Created by mesikkera on 16/10/2018.
//  Copyright © 2018 mesikkera. All rights reserved.
//

#include "PersonalContact.h"

// 복사 생성자
PersonalContact::PersonalContact(PersonalContact &personal)
{
    strlcpy(name, personal.name, 20);
    strlcpy(phoneNumber, personal.phoneNumber, 13);
    strlcpy(email, personal.email, 30);
    strlcpy(address, personal.address, 50);
}

// 연락처 입력
void PersonalContact::inputContact(char *inName, char *inPhoneNumber, char *inEmail, char *inAddress)
{
    if (inName != NULL)
        strlcpy(name, inName, 20);
    
    if (inPhoneNumber != NULL)
        strlcpy(phoneNumber, inPhoneNumber, 13);
    
    if (inEmail != NULL)
        strlcpy(email, inEmail, 30);
    
    if (inAddress != NULL)
        strlcpy(address, inAddress, 50);
}

// 연락처 조회
void PersonalContact::getContact(char *outName, char *outPhoneNumber, char *outEmail, char *outAddress)
{
    if (outName != NULL)
        strlcpy(outName, name, 20);
    
    if (outPhoneNumber != NULL)
        strlcpy(outPhoneNumber, phoneNumber, 13);
    
    if (outEmail != NULL)
        strlcpy(outEmail, email, 30);
    
    if (outAddress != NULL)
        strlcpy(outAddress, address, 50);
}

// 연락처 수정
void PersonalContact::editContact(char *inName, char *inPhoneNumber, char *inEmail, char *inAddress)
{
    if (inName != NULL)
        strlcpy(inName, inName, 20);
    
    if (inPhoneNumber != NULL)
        strlcpy(inPhoneNumber, inPhoneNumber, 13);
    
    if (inEmail != NULL)
        strlcpy(inEmail, inEmail, 30);
    
    if (inAddress != NULL)
        strlcpy(inAddress, inAddress, 50);
}

