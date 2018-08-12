#include <iostream>

using namespace std;

class Info
{
public:
    // 생성자
    Info() 
    {
        data = new int;
        data_arr = new int[3];
    }

    // 소멸자
    ~Info()
    {
        delete data;
        delete[] data_arr;
    }

    void Dispose()
    {
        delete data;
        delete[] data_arr;

        data = nullptr;
        data_arr = nullptr;
    }

private:
    int* data;
    int* data_arr;
};

int main()
{
    Info *info = new Info();

    cout << "Info: " << sizeof(info) << endl;
    cout << "Info Address: " << &info << endl;
    info -> Dispose();
    cout << "Info: " << sizeof(info) << endl;
    cout << "Info Address: " << &info << endl;
    delete info;
    cout << "Info: " << sizeof(info) << endl;
    cout << "Info Address: " << &info << endl;

    return 0;
}



