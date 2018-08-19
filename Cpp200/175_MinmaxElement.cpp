#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
    std::array<int, 5> data{5, 9, 4, 1, 7};

    // minmax_element(): 정렬되지 않은 컨테이너의 일부영역에서의 최소값과 최대값을 확인
    // minmax_element()의 리턴값: 컨테이너의 위치 2개
    // 1) 첫 번째: 컨테이너의 최소값 위치
    // 2) 두 번째: 컨테이너의 최대값 위치
    // 실제 값을 출력할 때는 위치를 담고 있기 때문에 포인터 연산자 이용
    // 시작위치에서 해당 위치를 빼면 인덱스 위치
    auto result1 = minmax_element(data.begin(), data.end());
    
    cout << "최소값 : " << *result1.first;
    cout << ", 위치 : " << (result1.first - data.begin()) << endl;
    cout << "최대값 : " << *result1.second;
    cout << ", 위치 : " << (result1.second - data.begin()) << endl;

    auto result2 = minmax_element(data.begin(), data.end(), [](int arg1, int arg2){
        return arg1 < arg2;
    });

    cout << "최소값 : " << *result2.first;
    cout << ", 위치 : " << (result2.first - data.begin()) << endl;
    cout << "최대값 : " << *result2.second;
    cout << ", 위치 : " << (result2.second - data.begin()) << endl;

    return 0;
}