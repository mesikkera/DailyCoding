#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(5);

    cout << "Size : " << v.size() << "    Capacity : " << v.capacity() << endl;
    vector<int>().swap(v);
    cout << "Size : " << v.size() << "    Capacity : " << v.capacity() << endl;

    return 0;
}