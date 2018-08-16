#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> data1({1, 2,3});
    vector<int> data2 = { 10, 20, 40 };

    data1.swap(data2);
    data1.insert(data1.begin() + 1, 20);

    cout << "== data1 ==" << endl;

    for (int i = 0; i < data1.size(); i++)
        cout << "data1 (" << i << ") : " << data1.at(i) << endl;

    cout << endl << "== data2 ==" << endl;

    for (int i = 0; i < data2.size(); i++)
        cout << "data2 (" << i << ") : " << data2.at(i) << endl;

    data2.erase(data2.begin(), data2.begin() + 2);

    data2.push_back(100);
    data2.push_back(200);
    data2.push_back(300);
    data2.pop_back();

    data2.insert(data2.end(), data1.begin(), data1.end());

    cout << endl << "== data2 == " << endl;

    for (int i = 0; i < data2.size(); i++)
        cout << "data2 (" << i << ") : " << data2.at(i) << endl;

    return 0;
}