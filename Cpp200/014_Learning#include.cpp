// #include <파일이름>: C++에서 제공하는 기본 라이브러리를 사용
// #include "파일 이름": 사용자가 만든 다른 파일을 참조할 때 사용

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> exam;
    exam.push_back(10);
    exam.push_back(20);
    exam.push_back(30);

    for (int i = 0, size = exam.size(); i < size; i++)
    {
        cout << "벡터 값: " << exam.at(i) << endl;
    }

    return 0;
}