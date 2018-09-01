#include <iostream>
using namespace std;

// 서버
// 서버에 클라이언트 정보를 제공하는 대표적인 방법
// : 함수 포인터 매개변수를 이용해 콜백 함수의 주소를 전달
// 배열의 모든 원소에 반복적인 작업을 수행하게 추상화됨 (구체적인 작업은 없다)
void For_each(int *begin, int *end, void (*pf)(int))
{
    while(begin != end)
    {
        pf(*begin++);        // 클라이언트 함수 호출(콜백)
        cout << "*begin : " << *begin << endl;
    }
}

// 클라이언트
void Print1(int n)          // 공백을 이용해 원소를 출력
{
    cout << n << ' ';
}

void Print2(int n)          // 각 원소를 제곱해 출력
{
    cout << n * n << endl;
}

void Print3(int n)          // 문자열과 endl을 이용해 원소를 출력
{
    cout << "Integer : " << n << endl;
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};

    For_each(arr, arr+5, Print1);       // Print1() 콜백 함수의 주소 전달
    cout << endl << endl;

    For_each(arr, arr+5, Print2);       // Print2() 콜백 함수의 주소 전달 
    cout << endl << endl;

    For_each(arr, arr+5, Print3);       // Print3() 콜백 함수의 주소 전달
    cout << endl << endl;

    return 0;  
}