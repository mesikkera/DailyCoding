#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int>> pq2;
	priority_queue<int, deque<int>, greater<int>> pq3;

	pq.push(10);
	pq.push(20);
	pq.push(30);
	pq.push(40);
	pq.push(40);
	pq.push(10);
	pq.push(20);

	while(!pq.empty()) {
		cout << pq.top() << " ";
		pq2.push(pq.top());
		pq.pop();
	}
	cout << endl;

	while(!pq2.empty()) { 
		cout << pq2.top() << " ";
		pq3.push(pq2.top());
		pq2.pop();
	}
	cout << endl;

	while(!pq3.empty()) { 
		cout << pq3.top() << " ";
		pq3.pop();
	}
	cout << endl;

	return 0;
}