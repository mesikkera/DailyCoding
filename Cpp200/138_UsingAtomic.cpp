#include <iostream>
#include <atomic>

using namespace std;

int main()
{
    atomic<int> data1(10);
    int number = 20;

    bool is_exchange = data1.compare_exchange_weak(number, 30);

    cout << boolalpha;
    cout << "data1 : " << data1 << " , number : " << number << " , " <<is_exchange << endl;

    atomic<int> data2 = ATOMIC_VAR_INIT(10);

    is_exchange = atomic_compare_exchange_weak(&data2, &number, 40);

    cout << "data2 : " << data2 << " , number : " << number << " , " << is_exchange << endl;

    return 0;
}