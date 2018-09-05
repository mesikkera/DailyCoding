#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

int main()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // i --> int type
    // v.size() --> unsigned int type 반환
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    cout << typeid(vector<int>::size_type).name() << endl;

    return 0;
}