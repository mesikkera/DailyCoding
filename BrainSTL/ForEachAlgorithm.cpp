#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(int n)
{
    cout << n << " ";
}

class PrintFunctor
{
    char fmt;

public:
    explicit PrintFunctor(char c = ' ') : fmt(c) { }
    void operator ()(int n) const 
    {
        cout << n << fmt;
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

    for_each(v.begin(), v.begin() + 2, Print);
    cout << endl;
    for_each(v.begin(), v.begin() + 4, Print);
    cout << endl;

    // [v.begin(), v.end()) 구간의 원소 출력
    for_each(v.begin(), v.end(), Print);
    cout << endl;

// for_each() 알고리즘과 함수자
    for_each(v.begin(), v.end(), PrintFunctor());       // 원소 구분을 ' '로 
    cout << endl;
    for_each(v.begin(), v.end(), PrintFunctor(','));    // 원소 구분을 ','로
    cout << endl;
    for_each(v.begin(), v.end(), PrintFunctor('\n'));   // 원소 구분을 '\n'로
    cout << endl;

    return 0;
}