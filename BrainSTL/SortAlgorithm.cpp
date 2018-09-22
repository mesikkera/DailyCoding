#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Greater(int left, int right)
{
    return left > right;
}

int main()
{
    vector<int> v;

    for(int i = 0;  i < 100; ++i)
        v.push_back(rand() % 1000);

    cout << "v[정렬 전] : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl << endl;

    sort(v.begin(), v.end());
    cout << "v[정렬 후] : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl << endl;

    sort(v.begin(), v.end(), Greater);
    cout << "v[정렬 greater] : ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

// stable_sort() 알고리즘
    vector<int> v1;

    v1.push_back(30);
    v1.push_back(50);
    v1.push_back(30);
    v1.push_back(20);
    v1.push_back(40);
    v1.push_back(10);
    v1.push_back(40);

    cout << "v1[정렬 전] : ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] << " ";
    cout << endl;

    stable_sort(v1.begin(), v1.end());
    cout << "v1[정렬 후] : ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] << " ";
    cout << endl;

    stable_sort(v1.begin(), v1.end(), Greater);
    cout << "v1[정렬 greater] : ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] << " ";
    cout << endl;

// partial_sort() 알고리즘
    vector<int> v2;

    for(int i = 0; i < 100; ++i)
        v2.push_back(rand() % 1000);
    
    partial_sort(v.begin(), v.begin() + 20, v.end());

    cout << "v2[상위 정렬 20개] : ";
    for(vector<int>::size_type i = 0; i < 20; ++i)
        cout << v2[i] << " ";
    cout << endl;

    cout << "v2[하위 정렬 20개] : "; 
    for(vector<int>::size_type i = 20; i < 100; ++i)
        cout << v2[i] << " ";
    cout << endl;

    



    return 0;
}