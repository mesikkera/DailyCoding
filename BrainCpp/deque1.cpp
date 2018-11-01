#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);

	for(auto i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";
	cout << endl;

	dq.push_front(-10);	
	dq.push_front(-20);

	for(auto i = 0; i < dq.size(); ++i)
			cout << dq[i] << " ";
	cout << endl;
	
	return 0;

}