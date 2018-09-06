#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(5);           // 기본값 0으로 초기화된 size가 5인 컨테이너

    v[0] = 10;
    v[1] = 20;
    v[2] = 30;
    v[3] = 40;
    v[4] = 50;

    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
    cout << "Size : " << v.size() << "    Capacity : " << v.capacity() << endl;

    // 사이즈 업
    // size가 늘어나면, capacity도 같이 늘어난다.
    v.resize(10);
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
    cout << "Size : " << v.size() << "    Capacity : " << v.capacity() << endl;

    // 사이즈 다운
    // size가 줄어들어도, capacity는 줄어들지 않는다.
    v.resize(5);
    for(vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
    cout << "Size : " << v.size() << "    Capacity : " << v.capacity() << endl;

    return 0;
}