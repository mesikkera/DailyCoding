#include <iostream>
#include <thread>

int main() {
	std::thread Thread1([]() {
		for(int i = 0; i < 5; ++i) {
			std::cout << "Thread1 Num : " << i << std::endl;
		}
	});

	std::thread Thread2;
	Thread2 = std::thread([]() {
		for(int i = 10; i < 15; ++i) {
			std::cout << "Thread2 Num : " << i << std::endl;
		}
	});

	std::thread Thread3;
	Thread3 = std::thread([](int nParam) {
		for(int i = 20; i < 25; ++i) {
			std::cout << "Thread3 Parameter : " << nParam << std::endl;
		}
	}, 4);

	return 0;
}