#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
struct Plus 
{
    T operator()(const T& left, const T& right) const 
    {
        return left + right;
    }
};

int main()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v3;
    transform(v1.begin(), v1.end(), v3.begin(), binder1st<plus<int>>(plus<int>(), 100));
    return 0;
}