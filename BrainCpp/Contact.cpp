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

// 연락처 목록 조회
void outputContactList()
{
    for(int i = 0; i < contactNumber; i++)
    {
        cout << i << " : " << contacts[i].name << endl;
    }
}

// 소유자 메뉴 실행
void runOwnerMenu()
{
    int menuNum;

    do {
        cout << "1. 소유자 정보 입력" << endl;
        cout << "2. 소유자 정보 조회" << endl;
        cout << "3. 이전 화면" << endl;
        cin >> menuNum;

        switch(menuNum)
        {
        case 1:
            inputOwnerInfo();
            break;
        case 2:
            outputOwnerInfo();
            break;
        case 3:
            cout << "이전 화면으로 돌아 갑니다." << endl;
            break;
        default:
            cout << "잘못 입력했습니다. 다시 해주세요." << endl;
        }
    } while (menuNum != 3);
}

// 연락처 메뉴 실행
void runContactMenu()
{
    int menuNum;

    do {
        cout << "1. 연락처 추가 입력" << endl;
        cout << "2. 연락처 목록 조회" << endl;
        cout << "3. 이전 화면" << endl;
        cin >> menuNum;

        switch(menuNum)
        {
        case 1:
            addContact();
            break;
        case 2:
            outputContactList();
            break;
        case 3:
            cout << "이전 화면으로 돌아갑니다." << endl;
            break;
        default:
            cout << "잘못 입력했습니다. 다시 해주세요" << endl;
        }
    } while(menuNum != 3);
}

// 조작 메뉴 기능
void runMainMenu()
{
    int menuNum;

    do {
        cout << "1. 소유자 관리 기능" << endl;
        cout << "2. 연락처 관리 기능" << endl;
        cout << "3. 프로그램 종료" << endl;
        cin >> menuNum;

        switch(menuNum)
        {
        case 1:
            runOwnerMenu();
            break;
        case 2:
            runContactMenu();
            break;
        case 3:
            cout << "프로그램을 종료합니다." << endl;
            break;
        default:
            cout << "잘못 입력했습니다. 다시 해주세요." << endl;
        }
    } while(menuNum != 3);
}