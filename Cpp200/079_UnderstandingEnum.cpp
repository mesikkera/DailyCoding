#include <iostream>

using namespace std;

// enum이 요소들은 정수형 값을 갖는다.
// 각 요소는 이전의 요소의 값보다 자동으로 1이 커진다.
// normal = 0 --> abnormal == 1
// disconnect = 100 --> close == 101
enum Status{
    normal = 0,
    abnormal, 
    disconnect = 100,
    close
};

int main()
{
    Status number = close;

    // enum 값 호출1
    if (number == Status::normal)
        cout << "Status : normal" << endl;
    // enum 값 호출2
    else if (number == abnormal)
        cout << "Status : abnormal" << endl;
    else if (number == 101)
        cout << "Status : disconnect" << endl;
    else
        cout << "Status : close" << endl;
    return 0;
}