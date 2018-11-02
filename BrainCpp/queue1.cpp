#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	// for(int i = 0; i < q.size(); ++i) { 
	// 	cout << q.front() << " ";
	// 	q.pop();
	// }

	int q_size = q.size();
	for(int i = 0; i < q_size; ++i) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	
	return 0;
}