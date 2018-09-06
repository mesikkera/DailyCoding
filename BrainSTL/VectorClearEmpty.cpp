#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(5);

    v[0] = 10;
    v[1] = 20;
    v[2] = 30;
    v[3] = 40;
    v[4] = 50;

    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
    cout << "Size : " << v.size() << "    Capacity : " << v.capacity() << endl;

    v.clear();      // v를 비운다.
    // clear() 이후에도 Capacity는 줄어들지 않는다.
    cout << "Size : " << v.size() << "    Capacity : " << v.capacity() << endl;

    if( v.empty()) {
        cout << "There is no data in vector" << endl;
    }
    return 0;
}