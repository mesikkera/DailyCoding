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

	void setName(string n) { 
		name.clear();
		name.append(n);
	}

	void getName() {
		cout << "name: " << name << endl;
	}
};

int main() {
	MyProfile profile1("allen");
	profile1.getName();

	MyProfile* ptrProfile1 = new MyProfile("andrew");
	ptrProfile1->getName();
	delete ptrProfile1;

	unique_ptr<MyProfile> uniqptrProfile1(new MyProfile("steven"));
	uniqptrProfile1->getName();

	return 0;
}