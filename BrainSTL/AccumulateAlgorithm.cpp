#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

template<typename T>
struct Plus 
{
    T operator()(const T& left, const T& right)
    {
        return left + right;
    }
};

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "v: ";
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    cout << accumulate(v.begin(), v.end(), 0) << endl;
    cout << accumulate(v.begin(), v.end(), 100) << endl;

// 함수류 버전 accumulate() 알고리즘
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    cout << "v1: ";
    for(vector<int>::size_type i = 0; i < v1.size(); ++i)
        cout << v1[i] << " ";
    cout << endl;

    // 사용자 함수자 합 연산 0 + 1 + 2 + 3 + 4 + 5
    cout << accumulate(v1.begin(), v1.end(), 0, Plus<int>()) << endl;
    // Plus 합 연산 0 + 1 + 2 + 3 + 4 + 5
    cout << accumulate(v1.begin(), v1.end(), 0, Plus<int>()) << endl;
    // multiplies 곱 연산 1 * 1 * 2 * 3 * 4 * 5
    cout << accumulate(v1.begin(), v1.end(), 1, multiplies<int>()) << endl;

    return 0; 
}