template <typename T>
class AutoArray
{
public:
    AutoArray(T* ptr)
    {
        _ptr = ptr;
    }

    ~AutoArray()
    {
        delete[] _ptr;
    }

    T& operator[] (int index)
    {
        return _ptr[index];
    }

private:
    T* _ptr;
};

int main()
{
    AutoArray<float> arr(new float [100]);

    arr[0] = 99.99f;

    return 0;
}