#include <iostream>
#include <atomic>

using namespace std;

int main()
{
    atomic<int> data1 = 10;
    atomic<int> data2 = ATOMIC_VAR_INIT(20);
    atomic_int data3 = ATOMIC_VAR_INIT(30);

    cout << data1 << ", " << data2 << ", " << data3 << endl;

    data1.store(11);
    data2.store(data3.load());

    atomic_store(&data3, 50);

    cout << data1 << ", " << data2 << ", " << data3 << endl;

    return 0;
}