#include <string>
#include <iostream>

using namespace std;

int main()
{
    string publisher = "mesikkera";
    string language = "C++";

    int x = 10;
    int y = 10;

    // A == B : A와 B가 같으면 참
    // A != B : A와 B가 다르면 참
    // A > B : A가 B보다 크면 참
    // A < B : A가 B보다 작으면 참
    // A >= B: A가 B보다 크거나 같으면 참
    // A <= B: A가 B보다 작거나 같으면 참
    if (publisher != language)
        cout << "두 문장은 같지 않습니다." << endl;
    else
        cout << "두 문장은 같습니다." << endl;
    
    if (x >= y)
        cout << "x는 y보다 크거나 같습니다." << endl;
    else
        cout << "x는 y보다 크거나 같지 않습니다." << endl;
    
    if (x <= 20)
        cout << "x는 20보다 작거나 같습니다." << endl;
    else
        cout << "x는 20보다 작거나 같지 않습니다." << endl;

    return 0;
}