#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <iostream>

using boost::bind;

int f(int a, int b) { 
	return a + b;
}

int g(int a, int b, int c) { 
	return a + b + c;
}

int main() {
	// bind()는 함수 객체를 리턴하는 함수
	// 리턴 값을 얻고 싶다면, 그 함수 객체를 operator()를 수행해야 한다.
	bind(f, 1, 2);				// f(1, 2);
	bind(g, 1, 2, 3);			// g(1, 2, 3);
	
	int x = 3;
	int y = 4;
	int z = 5;

	// _N 는 전달 되는 인수 목록의 N번째 자리의 인수를 _N이 써진 곳에 대입 하겠다.
	bind(f, _2, _1)(x, y);		// f(y, x);
	bind(g, _1, 9, _1)(x);		// g(x, 9, x);
	bind(g, _3, _3, _3)(x, y, z); 	// g(z, z, z)
	bind(g, _1, _1, _1)(x, y, z);	// g(x, x, x)

	int i = 5;

	// 사용법 1
	// f의 첫 번째 매개변수에 i를, 두 번째 매개변수에 x를 대입된 결과를 리턴
	std::cout << bind(f, i, _1)(x) << std::endl;


	// 사용법 2
	// f의 1번째 매개변수에 i를, 2번째 매개변수에 x를 대입된 함수 객체를 리턴
	bind(f, i, x);

	// 사용법 3
	// f의 1번째 매개변수에 1을, 2번째 매개변수에 i를 대입된 함수 객체를 리턴
	bind(f, 1, i);

	// 사용법 4
	// f의 1번째 매개변수에 x를, 2번째 매개변수에 x를 대입된 결과를 리턴
	std::cout << bind(f, _1, x)(x) << std::endl;

	// 함수 포인터형 선언
	typedef int (*FUNCPOINTER)(int, int);

	// 포인터에 f를 대입
	FUNCPOINTER funcpointer = f;

	// 결과 확인
	std::cout << bind(funcpointer, 1, 2)() << std::endl;

	return 0;

}