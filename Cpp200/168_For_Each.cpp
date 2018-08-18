#include <iostream>
#include <vector>
#include <algorithm>    // for_each 사용

using namespace std;

int main()
{
    vector<int> data({10, 20, 30, 40});

    cout << "== for_each 람다 ==" << endl;

    // for_each(): 배열 범위를 인자로 사용. 컨테이너와 람다 문법 응용 가능. 
    for_each(data.begin(), data.end(), [](int i) { cout << i << ", "; });

    cout << endl << "== for_each 람다 함수1 ==" << endl;

    auto Print = [](int x) { cout << x + x << ", "; };

    for_each(data.begin(), data.end(), Print);

    cout << endl << "== for_each 람다 함수2 == " << endl;

    int y = 11;

    for_each(data.begin(), data.end(), [y](int x) { cout << x + y << " , "; });

    cout << endl;
}