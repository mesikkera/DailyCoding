#include <iostream>

using namespace std;

// first namespace 
namespace first {
	int value = 1;
}

using namespace first;

// second namespace 
namespace second { 
	int value = 2;
}

using namespace second;

int main() 
{
	// cout << value << endl;
	cout << first::value << endl;
	cout << second::value << endl;
	return 0;
}