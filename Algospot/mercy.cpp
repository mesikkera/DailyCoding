/*
문제

The administrators of algospot.com are so merciful, that they prepared really, really easy problem to prevent contestants from frustration.

입력

Input contains just one positive integer N(N <= 10).

출력

Print N lines. Every line should contain 'Hello Algospot!'(quotation marks for clarity) and nothing else.

예제 입력

2
예제 출력

Hello Algospot!
Hello Algospot!
*/
#include <iostream>
using namespace std;

int main()
{
	int number = 0;
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		cout << "Hello Algosopt!" << endl;
	}
	return 0;
}