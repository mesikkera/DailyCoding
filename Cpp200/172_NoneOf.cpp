#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> data = {8, 27, 35, 49};

    // none_of(): 컨테이너 요소가 모두 조건에 맞지 않아야 true 리턴
    bool is_small = none_of(data.begin(), data.end(), [](int i){ return i > 100;});
    bool is_zero = none_of(data.begin(), data.end(), [](int i) { return i == 0;});

    if(is_small == true && is_zero)
        cout << "data 자료는 모두 100보다 작고 0이 아닙니다." << endl;

    return 0;
}