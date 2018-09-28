#include <iostream>
#include <functional>
using namespace std;

int main()
{
    binder1st<less<int> > binder = bind1st(less<int>(), 10);

}