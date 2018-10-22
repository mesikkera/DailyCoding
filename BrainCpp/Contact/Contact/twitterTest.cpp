//
//  twitterTest.cpp
//  Contact
//
//  Created by mesikkera on 22/10/2018.
//  Copyright © 2018 mesikkera. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include "include/freelecTwitcurl.h"

using namespace std;

int main(int argc, char* argv[])
{
    freelecTwitCurl twitterObj;
    
    // 트위터 아이디 및 비밀번호 설정
    string userName("mesikkera");
    string passWord("bbbb");
    
    // twitCurl 객체에 아이디 패스워드 설정
    twitterObj.setTwitterUsername(userName);
    twitterObj.setTwitterPassword(passWord);
    
    // ConsumerKey 및 SecretKey 생성
    twitterObj.setConsumerKey(string("LJ4uJ10E4hEYG30iCrftQ"));
    twitterObj.setConsumerSecret(string("vlYbnhUwLp0pEt1fISQyqet5Iw5wu5kW4RWOtERx8"));
    
    // 인증하기
    twitterObj.performAuth();
    
    // 트위터 follow 아이디 불러오기
    string nexCursor("");
    string UserID("atx686atx");
    
    // friendsIdsGet 함수 호출, friends/ids에 request를 보낸다.
    if(twitterObj.friendsIdsGet(nexCursor, UserID) == false) {
        cout << "Error!" << endl;
    }
    
    // ids 항목을 파싱해서 가져온다.
    string result = twitterObj.friendsIdsParse("ids");
    
    // 화면에 출력
    cout << "freelec-twitcurl test (friends/ids)" << endl;
    cout << result << endl;
}
