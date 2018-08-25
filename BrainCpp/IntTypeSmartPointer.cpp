class AutoArray
{
public:
    AutoArray(int* ptr)
    {
        _ptr = ptr;
    }

    ~AutoArray()
    {
        delete[] _ptr;
    }

    int& operator[] (int index)
    {
        return _ptr[index];
    }

private:
    int* _ptr;
};

int main()
{
    AutoArray arr(new int[100]);

    arr[0] = 100;

    return 0;
}