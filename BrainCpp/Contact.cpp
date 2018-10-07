#include <iostream>
using namespace std;

// 소유자 정보
// 이름, 전화번호, 이메일, 주소, 트위터 계정
struct OwnerInfo {
    char name[20];              // 이름
    char phoneNumber[13];       // 전화번호
    char email[30];             // 이메일
    char address[50];           // 주소
    char twitterAccount[20];    // 트위터 계정
};

 // 연락처 정보
 struct ContactInfo {
     char name[20];             // 이름
     char phoneNumber[13];      // 전화번호
     char email[30];            // 이메일
     char address[50];          // 주소
 };

// 전역 변수
OwnerInfo owner;
ContactInfo contacts[100];
int contactNumber = 0;

// 소유자 정보 관리 기능
void inputOwnerInfo()
{
    cout << "소유자 이름 : ";
    cin >> owner.name;

    cout << "소유자 전화번호 : ";
    cin >> owner.phoneNumber;

    cout << "소유자 이메일 : ";
    cin >> owner.email;

    cout << "소유자 주소 : ";
    cin >> owner.address;

    cout << "소유자 트위터 계정 : ";
    cin >> owner.twitterAccount;

    cout << "입력이 완료되었습니다." << endl;
}

// 소유자 정보 출력
void outputOwnerInfo()
{
    cout << "소유자 이름 : " << owner.name << endl;
    cout << "소유자 전화번호 : " << owner.phoneNumber << endl;
    cout << "소유자 이메일 : " << owner.email << endl;
    cout << "소유자 주소 : " << owner.address << endl;
    cout << "소유자 트위터 계정 : " << owner.twitterAccount << endl;
}

// 연락처 정보 관리 기능
// 연락처 정보 입력
void addContact()
{
    cout << "연락처 이름 : ";
    cin >> contacts[contactNumber].name;
    
    cout << "연락처 전화번호 : ";
    cin >> contacts[contactNumber].phoneNumber;

    cout << "연락처 이메일 : ";
    cin >> contacts[contactNumber].email;

    cout << "연락처 주소 : ";
    cin >> contacts[contactNumber].address;

    contactNumber++;
    cout << "입력이 완료 되었습니다." << endl;
}