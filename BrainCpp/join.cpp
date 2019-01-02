#include <thread>
#include <iostream>

using namespace std;

void func1() {
	cout << "my func1" << endl;
}

void func2(int val) {
	for(int i = 0; i < 1000; i++) {
		cout << val;
	}
}

int main() {
	thread t(&func1);
	t.join();

	thread t1(&func2, 1);
	thread t2(&func2, 2);

	for (int i=0; i < 1000; i++) {
		cout << 0;
	}
	
	t1.join();
	t2.join();

	for (int i=0; i < 1000; i++) {
		cout << 0;
	}

	return 0;
}