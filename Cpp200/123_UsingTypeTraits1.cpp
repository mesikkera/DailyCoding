#include <iostream>

using namespace std;

enum TmpEnum { };
enum class TmpEnumClass : int { };

int main()
{
    cout << boolalpha;

    // is_integral: 정수 계열의 형식인지 검사
    cout << "== is_integral ==" << endl;
    cout << "is_integral<TmpEnum>::value            : " << is_integral<TmpEnum>::value << endl;
    cout << "is_integral<TmpEnumClass>::value       : " << is_integral<TmpEnumClass>::value << endl;
    cout << "is_integral<signed int>::value         : " << is_integral<signed int>::value << endl;
    cout << "is_integral<unsigned int>::value       : " << is_integral<unsigned int>::value << endl;
    cout << "is_integral<double>::value             : " << is_integral<double>::value << endl;
    cout << "is_integral<bool>::value               : " << is_integral<bool>::value << endl;
    cout << endl;

    // is_enum: enum 계열의 형식인지 검사
    cout << "== is_enum ==" << endl;
    cout << "is_enum<TmpEnum>::value                : " << is_enum<TmpEnum>::value << endl;
    cout << "is_enum<TmpEnumClass>::value           : " << is_enum<TmpEnumClass>::value << endl;
    cout << "is_enum<int>::value                    : " << is_enum<int>::value << endl;
    cout << endl;

    // is_signed: signed 정수 계열의 형식인지 검사
    cout << "== is_signed ==" << endl;
    cout << "is_signed<TmpEnum>::value              : " << is_signed<TmpEnum>::value << endl;
    cout << "is_signed<signed int>::value           : " << is_signed<signed int>::value << endl;
    cout << "is_signed<unsigned int>::value         : " << is_signed<unsigned int>::value << endl;
    cout << endl;

    // is_unsigned: unsigned 정수 계열의 형식인지 검사
    cout << "== is_unsigned ==" << endl;
    cout << "is_unsigned<TmpEnumClass>::value       : " << is_unsigned<TmpEnumClass>::value << endl;
    cout << "is_unsigned<int>::value                : " << is_unsigned<int>::value << endl;
    cout << "is_unsigned(unsigned int)::value       : " << is_unsigned<unsigned int>::value << endl;
    cout << endl;
    
    return 0;
}