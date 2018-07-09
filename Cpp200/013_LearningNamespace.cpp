#include <iostream>

using namespace std;

// 네임스페이스: 변수나 함수를 해당 영역에서만 유효하도록 제한
namespace silla
{
    int year = 935;

    void CentralArea()
    {
        cout << "경상도" << endl;
    }
}

namespace baekjae
{
    int year = 660;

    void CentralArea()
    {
        cout << "충청도" << endl;
    }
}

// 네임스페이스 사용 선언: using 키워드
using namespace silla;
using namespace baekjae;

int main()
{
    cout << "신라 중심지: ";
    silla::CentralArea();
    cout << "신라 멸망연도: " << silla::year << endl;
    cout << "백제 중심지: ";
    baekjae::CentralArea();
    cout << "백제 멸망연도: " << baekjae::year << endl;

    return 0;
}