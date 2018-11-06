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
		cout << "name : " << name << endl;
	}
};

int main() {
	shared_ptr<MyProfile> shrdptrProfile1(new MyProfile("allen"));
	shrdptrProfile1->getName();

	auto shrdptrProfile2 = make_shared<MyProfile>("andrew");
	shrdptrProfile2->getName();

	return 0;
}