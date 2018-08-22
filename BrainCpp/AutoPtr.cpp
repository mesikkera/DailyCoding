#include <memory>
using namespace std;

int main()
{
    // 스마트 포인터 생성
    // int 타입을 가리킬 수 있는 스마트 포인터 p 정의
    auto_ptr<int> p(new int);

    // 스마트 포인터 사용
    *p = 100;

    // 메모리를 따로 해제해줄 필요 없다.

    return 0;
}