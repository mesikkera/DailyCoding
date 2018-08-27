#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

template <typename T>
void ShowRange(const char* typeName)
{
    cout << setw(20) << right << typeName << " (" << sizeof(T) << ") = " << setw(15) << right << numeric_limits<T>::min() << " ~ " 
         << setw(15) << left << numeric_limits<T>::max() << "\n";
}

int main()
{
    ShowRange<signed char> ("signed char");
    ShowRange<unsigned char> ("unsigned char");
    ShowRange<signed short> ("signed short");
    ShowRange<unsigned short> ("unsigned short");
    ShowRange<signed int>   ("signed int");
    ShowRange<unsigned int> ("unsigned int");
    ShowRange<signed long> ("signed long");
    ShowRange<unsigned long> ("unsigned long");
    ShowRange<float> ("float");
    ShowRange<double> ("double");

    return 0;
}