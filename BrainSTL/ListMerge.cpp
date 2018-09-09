#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> lt1;
    list<int> lt2;

    lt1.push_back(10);
    lt1.push_back(20);
    lt1.push_back(30);
    lt1.push_back(40);
    lt1.push_back(50);

    lt2.push_back(25);
    lt2.push_back(35);
    lt2.push_back(60);

    list<int>::iterator iter;
    cout << "lt1 : ";
    for(iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "lt2 : ";
    for(iter = lt2.begin(); iter != lt2.end(); ++iter)
        cout << *iter << " ";
    cout << endl << "=============================" << endl;

    lt1.merge(lt2);     // lt2를 lt1으로 합볍 정렬. 정렬 기준은 less

    cout << "lt1 : ";
    for(iter = lt1.begin(); iter != lt1.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    cout << "lt2 : ";
    for(iter = lt2.begin(); iter != lt2.end(); ++iter)
        cout << *iter << " ";
    cout << endl << "=============================" << endl;


    // list의 조건자 버전 merge()
    list<int> lt3;
    list<int> lt4;

    lt3.push_back(50);
    lt3.push_back(40);
    lt3.push_back(30);
    lt3.push_back(20);
    lt3.push_back(10);

    // lt3과 lt4의 정렬방식이 다르므로 오류
    // lt4.push_back(25);
    // lt4.push_back(35);
    // lt4.push_back(60);

    // lt3과 lt4는 정렬 방식이 같음.
    // greater 조건자 ( > 연산) 정렬기준 사용
    lt4.push_back(60);
    lt4.push_back(35);
    lt4.push_back(25);

    list<int>::iterator iter3;
    cout << "lt3 : ";
    for(iter3 = lt3.begin(); iter3 != lt3.end(); ++iter3)
        cout << *iter3 << " ";
    cout << endl;

    cout << "lt4 : ";
    for(iter3 = lt4.begin(); iter3 != lt4.end(); ++iter3)
        cout << *iter3 << " ";
    cout << endl << "===============================" << endl;

    // lt4를 lt3으로 합병 정렬
    // 두 list의 정렬 기준이 greater(>연산) 라는 것을 predicate로 지정
    lt3.merge(lt4, greater<int>());

    cout << "lt3 : ";
    for(iter3 = lt3.begin(); iter3 != lt3.end(); ++iter3)
        cout << *iter3 << " ";
    cout << endl;

    cout << "lt4: ";
    for(iter3 = lt4.begin(); iter3 != lt4.end(); ++iter3)
        cout << *iter3 << " ";
    
    return 0;
}