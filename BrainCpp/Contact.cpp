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

class Owner 
{
private:
    char name[20];              // 이름
    char phoneNumber[13];       // 전화번호
    char email[30];             // 이메일
    char address[50];           // 주소
    char twitterAccount[20];    // 트위터 계정

public:
    // 소유자 정보 입력
    void inputOwnerInfo(char* inName, char* inPhoneNumber=NULL, char* inEmail=NULL, char* inAddress=NULL, char* inTwitterAccount=NULL);
    // 소유자 정보 출력
    void printOwnerInfo();
    // 소유자 정보 수정
    void editOwnerInfo(char* inName, char* inPhoneNumber=NULL, char* inEmail=NULL, char* inAddress=NULL, char* inTwitterAccount=NULL);
};

 // 연락처 정보
 struct ContactInfo {
     char name[20];             // 이름
     char phoneNumber[13];      // 전화번호
     char email[30];            // 이메일
     char address[50];          // 주소
 };

 // 클래스: 연락처 정보
 class PersonalContact
 {
private:
    char name[20];              // 이름
    char phoneNumber[13];       // 전화번호
    char email[30];             // 이메일
    char address[50];           // 주소

public:
    // 기본 생성자
    PersonalContact() {}
    // 복사 생성자
    PersonalContact(PersonalContact &personal);
    // 연락처 입력
    void inputContact(char* inName, char* inPhoneNUmber=NULL, char* inEmail=NULL, char* inAddress=NULL);
    // 연락처 조회
    void getContact(char* outName, char* outPhoneNumber, char* outEmail, char* outAddress);
    // 연락처 수정
    void editContact(char* inName, char* inPhoneNuber=NULL, char* inEmail=NULL, char* inAddress=NULL);
 };


// 연락처 전체를 관리하는 클래스: Contact
class Contact
{
private:
    PersonalContact contactInfo[100];       // 100명의 연락처 저장 가능한 배열
    int numberOfContact;                    // 현재 저장된 연락처 개수

public:
    // 생성자 - 멤버 초기화를 위해 생성
    Contact();
    // 연락처 정보 입력
    void inputContact(char* name, char* phoneNumber=NULL, char* email=NULL, char* address=NULL);
    // 연락처 전체 목록 조회
    void printContactList();
    // 연락처 상세 조회 - 함수 오버로딩
    void printContat(int index);
    void printContact(char* inName);
    // 연락처 수정
    void editContactByIndex(int index, char* inName, char* phoneNumber=NULL, char* email=NULL, char* address=NULL);
    // 연락처 복사
    void copyContact(int index);
    // 연락처 제거
    void removeContactByIndex(int index);
};

class Menu 
{
private:
    char topMenu[3][32];                // 최상위 메뉴 정보
    char ownerMenu[4][32];              // 소유자 메뉴 정보
    char contactMenu[7][32];            // 연락처 메뉴 정보
    int menuType;                       // 0: 최상위 메뉴, 1: 소유자 메뉴, 2: 연락처 메뉴

public:
    Menu();                             // 생성자
    void showMenu();                    // 현재 메뉴 선택 상태를 통해 메뉴 목록 출력
    void setMenuSelection(int selection);
    void execute();                     // 선택한 메뉴 실행
};

// Menu 클래스를 이용하여 조작을 수행하는 클래스: Controller
class Controller 
{
private:
    Contact contact;
    Menu menu;
    Owner owner;

    void inputOwnerInfo();              // 소유자 정보 입력
    void printOwnerInfo();              // 소유자 정보 출력
    void editOwnerInfo();               // 소유자 정보 출력

    void addContact();                  // 연락처 정보 입력
    void printContactList();            // 연락처 전체 목록 조회
    void printContactDetail();          // 연락처 상세 조회
    void editContact();                 // 연락처 수정
    void copyContact();                 // 연락처 복사
    void removeContact();               // 연락처 삭제
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

// 소유자 정보 관리 기능
void editOwnerInfo()
{
    int inputNum;
    
    cout << "1. 소유자 이름 수정" << endl;
    cout << "2. 소유자 전화번호 수정" << endl;
    cout << "3. 소유자 이메일 수정" << endl;
    cout << "4. 소유자 주소 수정" << endl;
    cout << "5. 소유자 트위터 계정 수정" << endl;
    cout << "6. 수정없이 이전 메뉴로" << endl;
    cin >> inputNum;

    switch(inputNum)
    {
    case 1:
        cin >> owner.name;
        cout << "소유자의 이름이 수정되었습니다." << endl;
        break;

    case 2:
        cin >> owner.phoneNumber;
        cout << "소유자의 전화번호가 수정되었습니다." << endl;
        break;

    case 3:
        cin >> owner.email;
        cout << "소유자의 이메일이 수정되었습니다." << endl;
        break;

    case 4: 
        cin >> owner.address;
        cout << "소유자의 주소가 수정되었습니다." << endl;
        break;

    case 5:
        cin >> owner.twitterAccount;
        cout << "소유자의 트위터 계정이 수정되었습니다." << endl;
        break;

    default:
        cout << "아무것도 수정되지 않았습니다." << endl;
    }
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

// 연락처 관리 기능 구현: 인덱스로 연락처 삭제
int removeContactByIndex(int index)
{
    // index가 0보다 작거나 contactNumber보다 크면 삭제 불가
    if((index >= contactNumber) || (index < 0))
        return 0;

    int i;
    for(i = index + 1; i < contactNumber; i++)
    {
        *(contacts + 1 - i) = *(contacts + 1);
    }

    contactNumber--;

    return 1;
}

// 개별 연락처 출력
void printContactInfoByIndex(int index)
{
    cout << index << "의 index를 가진 연락처 조회" << endl;
    cout << "연락처 이름: " << contacts[index].name << endl;
    cout << "연락처 전화번호: " << contacts[index].phoneNumber << endl;
    cout << "연락처 이메일: " << contacts[index].email << endl;
    cout << "연락처 주소: " << contacts[index].address << endl;
}

// 소유자 메뉴 실행
void runOwnerMenu()
{
    int menuNum;

    do {
        cout << "1. 소유자 정보 입력" << endl;
        cout << "2. 소유자 정보 조회" << endl;
        cout << "3. 소유자 정보 수정" << endl;
        cout << "4. 이전 화면" << endl;
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
            editOwnerInfo();
            break;
        case 4:
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
    int index;
    int result;

    do {
        cout << "1. 연락처 추가 입력" << endl;
        cout << "2. 연락처 목록 조회" << endl;
        cout << "3. 연락처 삭제" << endl;
        cout << "4. 연락처 상세 조회" << endl;
        cout << "5. 이전 화면" << endl;
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
            cout << "삭제할 연락처 index";
            cin >> index;
            result = removeContactByIndex(index);
            if(result == 1)
                cout << "정상적으로 삭제되었습니다." << endl;
            else
                cout << "정상적으로 삭제되지 않았습니다." << endl;
            break;
        case 4:
            cout << "조회할 연락처 index : " ;
            cin >> index;
            printContactInfoByIndex(index);
            break;
        case 5:
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

int main()
{
    runMainMenu();
    return 0;
}