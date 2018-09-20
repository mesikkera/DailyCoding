#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i) 
        cout << v[i] << " ";
    cout << endl;

    // #include <ctime> 추가 랜덥 초깃값
    // srand((unsigned)time(NULL));

    // 원소를 뒤섞는다.
    random_shuffle(v.begin(), v.end());
    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i) 
        cout << v[i] << " ";
    cout << endl;

    // 원소를 뒤섞는다.
    random_shuffle(v.begin(), v.end());
    cout << "v : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i) 
        cout << v[i] << " ";
    cout << endl;

    return 0;
}