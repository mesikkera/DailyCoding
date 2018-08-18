#include <iostream>
#include <array>

using namespace std;

void Print(const array<int, 3> &data)
{
    cout << "== Print ==" << endl;
    for (auto iter = data.begin(); iter != data.end(); ++iter)
        cout << *iter << ", ";

    cout << endl;
}

int main()
{   
    // array 생성
    // array는 vector와 사용 방법이 비슷, 크기 고정
    array<int, 3> data1 {10, 2, 5};
    array<int, 3> data2;
    
    // fill(): array 전체를 특정값으로 설정할 때 사용
    // data2: {0, 0, 0}
    data2.fill(0);
    // array -> random access 허용 -> at() 함수를 호출하여
    // 두 번째 인자 값을 200으로 설정 가능.
    data2.at(1) = 200;

    // {0, 200, 0}
    Print(data2);

    // array copy
    // data1: {10, 2, 5}, data2: {0, 200, 0}
    // copy() --> data2: {10, 2, 5}
    copy(data1.begin(), data1.end(), data2.begin());

    // data1: {10, 2, 5}
    Print(data1);
    // data2: {10, 2, 5} 
    Print(data2);

    return 0;
}