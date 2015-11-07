#include <iostream>
using namespace std;

// 템플릿으로 만든 값을 비교하는 Max 함수
template <typename T> T Max(T a, T b)
{
	return a > b ? a : b;
}

int main(void)
{
	int Char1_HP = 300;
	int Char2_HP = 400;
	int MaxCharHP = Max(Char1_HP, Char2_HP);
	cout << "HP 중 가장 큰 값은 " << MaxCharHP << "입니다." << endl << endl;

	float Char1_Exp = 250.0f;
	float Char2_Exp = 250.57f;
	float MaxCharExp = Max(Char1_Exp, Char2_Exp);
	cout << "경험치 중 가장 큰 값은 " << MaxCharExp << "입니다." << endl << endl;

	return 0;
}