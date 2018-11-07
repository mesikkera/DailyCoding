#include <iostream>
#include <vector>

using namespace std;

int main() {
	int numArray[] = {2, 4, 6, 8, 10};

	for(int i : numArray) {		// 배열 반복
		cout << i << " ";
	}
	cout << endl;

	vector<int> numVector;
	numVector.push_back(1);
	numVector.push_back(3);
	numVector.push_back(5);
	numVector.push_back(7);
	numVector.push_back(9);

	for (int i : numVector) {	// 배열 반복
		cout << i << " ";
	}
	cout << endl;
	
	return 0;
}