#include <iostream>
#include <string>
#include <memory>

using namespace std;

class MyProfile {
private:
	string name;

public:
	MyProfile(string n) {
		name.append(n);
	}
	~MyProfile() {
		name.clear();
		cout << "destructor called." << endl;
	}

	void setName(string n) {
		name.clear();
		name.append(n);
	}

	void getName() {
		cout << "name : " << name << endl;
	}
};

int main() {
	MyProfile* ptrProfile1 = new MyProfile("allen");
	ptrProfile1->getName();
	// delete ptrProfile1;

	auto shrdpProfile1 = make_shared<MyProfile>("andrew");
	shrdpProfile1->getName();

	return 0;
}