#include <iostream>
#include <list>

using namespace std;

void Print(const list<int> &data)
{
    cout << "== Print ==" << endl;

    for (auto iter = data.begin(); iter != data.end(); ++iter)
        cout << *iter << endl;

    cout << endl;
}

int main()
{
    list<int> data1({1, 2, 3,2});
    data1.push_back(3);
    data1.sort();
    
    Print(data1);

    data1.unique();

    Print(data1);

    list<int> data2 = {4, 5, 6};
    data2.merge(data1);

    Print(data2);
    return 0;
}