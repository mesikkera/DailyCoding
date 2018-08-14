#include <iostream>
#include <atomic>

using namespace std;

int main()
{
    atomic<int> data1(10);
    atomic<int> data2 = ATOMIC_VAR_INIT(20);
    atomic<int> data3 = data1.exchange(data2.load());

    cout << data1 << ", " << data2 << ", " << data3 << endl;

    atomic_exchange(&data1, data3);
    atomic_exchange(&data2, data1.load());
    atomic_exchange(&data3, 5);

    cout << data1 << ", " << data2 << ", " << data3 << endl;

    return 0;    
}