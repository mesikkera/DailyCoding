/**********************************************************
* Project Euler Problem 001                                *
************************************************************
* Multiples of 3 and 5                                     *
* If we list all the natural numbers below 10 that are     *
* multiples of 3 or 5, we get 3, 5, 6, and 9. The sun of   *
* these multiples is 23. Find the sun of all the multiples *
* of 3 or 5 below 1000.                                    *
***********************************************************/

#include<iostream>

int main()
{
	int i , result = 0;

	for(i=1;i<1000;i++){
		if(i%3 == 0 || i%5 ==0)
			result += i;
	}
	std::cout<<result<<std::endl;
}

