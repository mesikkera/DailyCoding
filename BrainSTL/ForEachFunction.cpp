#include <iostream>
using namespace std;

// begin은 배열의 시작 주소, end는 배열의 끝 주소,
// pf는 클라이언트 함수 포인터이다.
void For_each(int* begin, int* end, void (*pf)(int)){
    while (begin != end) {
        pf(*begin++);
    }
}

void PrintInt(int n) {
    cout << n << " ";
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    For_each(arr, arr+5, PrintInt);     // 정수 출력
    cout << endl;

    return 0;
}