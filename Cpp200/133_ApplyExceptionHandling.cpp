#include <iostream>
#include <vector>
#include <string>

using namespace std;

class InputError : public runtime_error
{
public:
    InputError(int idx, string msg)
        : runtime_error("")
    {
        cout << idx << "번 인덱스에 잘못된 입력값: " << msg << endl;
    }
};

int main()
{
    vector<int> data;
    data.push_back(1);

    int idx = 10;
    int value = 20;

    try
    {
        if (idx >= data.size())
            throw InputError(idx, to_string(value));
            data.at(idx) = 99;
    }
    catch (InputError e)
    {
        cout << e.what();
    }

    return 0;
}