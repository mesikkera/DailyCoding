#include <iostream>
using namespace std;

int main()
{
    // 배열 정의
    long lArray[20];

    // 포인터가 lArray배열을 가리키도록 정의
    long (*p)[20] = &lArray;
    // long* p[20] = &lArray; => [,]는 *보다 우선순위가 높아 컴파일러에서 먼저 해석을 한다.
    //                           따라서 long * p[20]이라고 정의할 경우
    //                           p[20]이 먼저 해석되고 그 후에 long*이 해석되므로, 
    //                           long타입의 원소 20개를 가지는 배열에 대한 포인터로 최종 해석한다.

    // 포인터를 통해서 배열 사용
    (*p)[3] = 200;

    // 결과 확인
    cout << "lArray[3] = " << lArray[3] << endl;

    // 3개의 원소를 가진 포인터의 배열을 정의한다.
    double a, b, c;
    double* pArray[3];

    // 각 원소가 변수들을 가리키게 정의
    pArray[0] = &a;
    pArray[1] = &b;
    pArray[2] = &c;
    
    return 0;
}