#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(5);

    cout << "Size : " << v.size() << "    Capacity : " << v.capacity() << endl;
    vector<int>().swap(v);
    cout << "Size : " << v.size() << "    Capacity : " << v.capacity() << endl;

    // 두 vector 컨테이너 v1과 v2를 swap()으로 교환
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v2;
    v2.push_back(100);
    v2.push_back(200);
    v2.push_back(300);

    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] << ", " << v2[i] << endl;
    cout << endl;

    v1.swap(v2);    // v1과 v2를 swap
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] << ", " << v2[i] << endl;
    cout << endl;

    return 0;
}