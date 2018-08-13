#include <iostream>
#include <map>

using namespace std;

struct TmpStruct 
{
    int x = 0;
};

class TmpClass
{

};

int main()
{
    cout << boolalpha;

    // is_empty: 내부 요소가 비어 있는지 확인
    cout << "== is_empty ==" << endl;
    cout << "is_empty<TmpStruct>::value             : " << is_empty<TmpStruct>::value << endl;
    cout << "is_empty<TmpClass>::value              : " << is_empty<TmpClass>::value << endl;

    // is_array: 배열 형식인지 확인
    cout << "== is_array ==" << endl;
    cout << "is_array<TmpStruct>::value             : " << is_array<TmpStruct>::value << endl;
    cout << "is_array<map<int, double>>::value      : " << is_array<map<int, double>>::value << endl;
    cout << "is_array<int[3]>::value                : " << is_array<int[3]>::value << endl;

    // is_same: 두 형식을 비교해서 같다면 true, 다르면 false
    cout << "== is_same ==" << endl;
    cout << "is_same<TmpStruct, TmpClass>::value    : " << is_same<TmpClass, TmpStruct>::value << endl;
    cout << "is_same<int, signed int>::value        : " << is_same<int, signed int>::value << endl;
    cout << "is_same<int, bool>::value              : " << is_same<int, bool>::value << endl;
    cout << "is_same<char, unsigned char>::value    : " << is_same<char, unsigned char>::value << endl;

    return 0;
}
