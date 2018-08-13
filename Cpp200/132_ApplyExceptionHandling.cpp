#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> data;
    data.push_back(1);

    // 유형에 맞춰 원하는 에러 메세지를 출력할 수 있다.
    // 로그 파일을 만들 때 아래와 같이 작성하면
    // 에러 발생 지점을 정확히 잡아낼 수 있다.
    try
    {
        if (data.empty() == true)
            // throw: 예외 상황과 에러 조건을 다른 코드에 알려주는 키워드
            throw "Vector is Empty!";

        if (data.size() < 2) 
            throw 99;
    }

    catch (char* e)
    {
        cout << "catch (char* e) " << e << endl;
    }

    catch(int e)
    {
        cout << "catch (int e) " << e << endl;
    }

    return 0;
}