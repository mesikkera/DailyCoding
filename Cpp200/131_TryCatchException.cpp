#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> data;
    int number = 0;

    try
    {
        // 유효하지 않은 벡터 인덱스에 접근
        number = data.at(10);
    }
    catch(exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}