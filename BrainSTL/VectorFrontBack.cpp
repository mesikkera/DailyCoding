#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    cout << v[0] << ", " << v.front() << endl;      // 첫 번째 원소
    cout << v[4] << ", " << v.back() << endl;       // 마지막 원소
    
    v.front() = 100;        // 첫 번째 원소를 100으로
    v.back() = 500;         // 마지막 원소를 500으로

    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    v[0] = 100;     // 범위점검 없는 0 index 원소의 참조
    v[4] = 500;     // 범위점검 없는 4 index 원소의 참조
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    v.at(0) = 1000; // 범위 점검 있는 0 index 원소의 참조
    v.at(4) = 5000; // 범위 점검 있는 4 index 원소의 참조
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    try {
        cout << v.at(0) << endl;
        cout << v.at(3) << endl;
        cout << v.at(6) << endl;
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }

    v.assign(5, 2);     // 5개의 원소값을 2로 할당
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    // begin(), end()
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    return 0;
}