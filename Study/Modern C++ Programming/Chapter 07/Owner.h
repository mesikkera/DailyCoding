#include <iostream>

class Owner {
private:
	char name[20];
	char phoneNumber[13];
	char email[30];
	char address[50];
	char twitterAccount[20];

public:
	// input owner info
	void inputOwnerInfo(char *inName, char *inPhoneNumber = NULL, char *inEmail = NULL, char *inAddress = NULL, char *inTwitterAccount = NULL);

	// print owner info
	void printOwnerInfo();

	// edit owner Info
	void editOwnerInfo(char *inName, char *inPhoneNumber = NULL, char *inEmail = NULL, char *inAddress = NULL, char *inTwitterAccount = NULL);
};