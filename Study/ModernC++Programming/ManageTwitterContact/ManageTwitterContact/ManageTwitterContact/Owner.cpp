#include "Owner.h"

using namespace std;

// 소유자 정보 입력
void Owner::inputOwnerInfo(char *inName, char *inPhoneNumber, char *inEmail, char *inAddress, char *inTwitterAccount)
{
	if (inName != NULL)
		strcpy_s(name, 20, inName);

	if (inPhoneNumber != NULL)
		strcpy_s(phoneNumber, 13, inPhoneNumber);

	if (inEmail != NULL) 

}