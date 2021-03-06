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

    v.clear();
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // begin(), end()
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    vector<int>::iterator iter = v.begin();     // 시작 원소를 가리킨다.
    cout << *iter << endl;

    iter += 2;      // +2한 위치의 원소를 가리킨다. 
    cout << *iter << endl;

    iter -= 1;      // -1한 위치의 원소(20)를 가리킨다.
    cout << *iter << endl;

    // 이미 선언되어 있으므로 생략
    // vector<int>::iterator iter = v.begin();
    vector<int>::const_iterator citer = v.begin();

    cout << *iter << endl;      // 가리키는 원소의 참조
    cout << *citer << endl;     // 가리키는 원소의 상수 참조

    cout << *iter << endl;      // 다음 원소로 이동한 원소의 참조
    cout << *citer << endl;     // 다음 원소로 이동한 원소의 상수 참조

    *iter = 100;                // 일반 반복자는 가리키는 원소를 변경할 수 있음
    // *citer = 100;            // 상수 반복자는 가리키는 원소를 변경할 수 없음.

    // const와 반복자
    int arr[5] = {10, 20, 30, 40, 50};
    int* p = arr;
    cout << *iter << ", " << *p << endl;    // iter는 p처럼 동작

    const int* cp = arr;
    cout << *citer << ", " << *cp << endl;  // citer는 cp처럼 동작

    const vector<int>::iterator iter_const = v.begin();
    int* const p_const = arr;               // iter_const는 p_const 처럼 동작
    cout << *iter_const << ", " << *p_const << endl;

    const vector<int>::const_iterator citer_const = v.begin();
    const int* const cp_const = arr;        // citer_const는 cp_const처럼 동작
    cout << *citer_const << ", " << *cp_const << endl;

    // 역방향 반복자
    vector<int>::reverse_iterator riter;

    v[1] = 20;
    for(riter = v.rbegin(); riter != v.rend(); ++riter)
        cout << *riter << " ";
    cout << endl;

    // insert() 멤버 함수의 사용
    vector<int>::iterator iter2 = v.begin() + 2;
    vector<int>::iterator iter3;

    iter3 = v.insert(iter2, 100);

    for(iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    cout << "iter3 : " << *iter3 << endl;


    return 0;
}