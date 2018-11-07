#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Multiplier {
	int first;
	int second;

public:
	Multiplier(int f, int s) {
		first = f;
		second = s;
	}

	int getResult() {
		return first * second;
	}
};

int main() {
	vector<Multiplier> multipleData;

	for(int i = 0; i < 10; i++) {
		Multiplier multiple = Multiplier(rand() % 10, rand() % 10);
		multipleData.push_back(multiple);
	}

	cout << "정렬되지 않은 결과" << endl;
	for(vector<Multiplier>::iterator iter = multipleData.begin(); iter != multipleData.end(); iter++) {
		cout << iter -> getResult() << endl;
	}

	sort(multipleData.begin(), multipleData.end(), [](Multiplier& m1, Multiplier& m2) {
		return m1.getResult() < m2.getResult();
	});

	cout << "정렬된 결과" << endl;
	for(vector<Multiplier>::iterator iter = multipleData.begin(); iter != multipleData.end(); iter++) {
		cout << iter->getResult() << endl;
	}
	return 0;


}