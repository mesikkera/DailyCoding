#include <iostream>
#include <atomic>

using namespace std;

int main() {
	// atomic<int> intAtomic = 1;
	atomic<int> intAtomic = 1;

	intAtomic.fetch_add(1);					// 값 1 증가. 결과는 2
	cout << intAtomic << endl;

	intAtomic.fetch_sub(2);					// 값 2 감소. 결과는 0

	return 0;
}