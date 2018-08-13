#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<class T>
class TemplateData
{
public:
    void Add(T arg)
    {
        data_.push_back(arg);
    }

    int Size()
    {
        data_.size();
    }

    void Print()
    {
        for(int i = 0, size = data_.size(); i < size; i++)
            cout << "data_ : " << data_.at(i) << endl;
    }

private:
    vector<T> data_;
};

int main()
{
    TemplateData<int> data_int;
    data_int.Add(1);
    data_int.Add(2);
    data_int.Print();

    TemplateData<string> data_string;
    data_string.Add("Hello");
    data_string.Add("World");
    data_string.Add("!!");
    data_string.Print();

    return 0;
}