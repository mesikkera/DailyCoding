#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
struct Less 
{
    bool operator()(const T& left, const T& right) const 
    {
        return left < right;
    }
};
int main()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(50);

    vector<int> v3;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);
    
    if(lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()))
        cout << "v1 < v2" << endl;
    else 
        cout << "v1 >= v2" << endl;

    if(lexicographical_compare(v1.begin(), v1.end(), v3.begin(), v3.end()))
        cout << "v1 < v3" << endl;
    else 
        cout << "v1 >= v3" << endl;

// 조건자 버전의 lexicographical_compare() 알고리즘
    vector<int> v4;
    v4.push_back(10);
    v4.push_back(20);
    v4.push_back(30);

    vector<int> v5;
    v5.push_back(10);
    v5.push_back(25);
    v5.push_back(50);

    if(lexicographical_compare(v4.begin(), v4.end(), v5.begin(), v5.end(), less<int>()))
        cout << "기준 less v4와 v5의 비교 : true" << endl;
    else 
        cout << "기준 less v4와 v5의 비교 : false" << endl;

    if(lexicographical_compare(v4.begin(), v4.end(), v5.begin(), v5.end(), greater<int>()))
        cout << "기준 greater v4와 v5의 비교 : true" << endl;
    else 
        cout << "기준 greater v4와 v5의 비교 : false" << endl;

    if(lexicographical_compare(v4.begin(), v4.end(), v5.begin(), v5.end(), Less<int>()))
        cout << "사용자 기준 less v4와 v5의 비교 : true" << endl;
    else 
        cout << "사용자 기준 less v4와 v5의 비교 : false" << endl;


    return 0;
}