#include <cstdio>
#include <thread>

using namespace std;

class Counter {
public:
	Counter(int id, int length) {
		mId = id;
		mLength = length;
	}

	void operator()() const {
		for(int i = 1; i <= mLength; i++) {
			printf("counter[%d] : %d\n", mId, i);
		}
	}

private:
	int mId;
	int mLength;
};

int main() {
	// # 1
	thread t1{Counter(1, 5)};

	// #2
	Counter c2(2, 7);
	thread t2(c2);

	// #3
	thread t3(Counter(3, 8));

	t1.join();
	t2.join();
	t3.join();

	return 0;
}