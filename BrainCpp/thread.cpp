#include <iostream>
#include <thread>

using namespace std;

// thread에 의해 호출되는 함수
void call_from_thread(int tid) { 
	cout << "스레드 실행 " << tid << endl;
}

int main() {
	thread t[10];

	// 10개의 쓰레드 시작
	for(int i = 0; i < 10; i++) {
		t[i] = thread(call_from_thread, i);
	}

	cout << "메인 함수 시작" << endl;

	// 쓰레드가 종료될 때까지 대시
	for(int i = 0; i < 10; i++) {
		t[i].join();
	}

	return 0;
}