#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    // vector<typename T, typename Alloc = allocator<T>>
    // vector<int> 같음
    vector<int, allocator<int>> v;  // vector의 두 번째 템플릿 매개변수가 할당기를 인자로 받는다. 첫 번째 매개변수는 저장 객체 타입
    v.push_back(10);
    cout << *v.begin() << endl;

    // set<typename T, typename Pred = less<T>, typename Aoolc = allocator<T>>, set<int> 와 동일
    set<int, less<int>, allocator<int>> s;
    s.insert(10);
    cout << *s.begin() << endl;

    return 0;
}