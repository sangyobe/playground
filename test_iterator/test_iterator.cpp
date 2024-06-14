#include <algorithm>
#include <iostream>

class MyIter
{
public:
    MyIter(int *p) : _ptr(p)
    {
    }
    MyIter &operator++()
    {
        _ptr++;
        return *this;
    }
    int &operator*()
    {
        return *_ptr;
    }
    bool operator==(const MyIter &ref)
    {
        return (ref._ptr == _ptr);
    }
    bool operator!=(const MyIter &ref)
    {
        return (ref._ptr != _ptr);
    }

private:
    int *_ptr;
};

class MyArr
{
public:
    MyArr(int size = 10)
    {
        _size = size;
        _arr = new int(size);
    }
    typedef MyIter iterator;
    iterator begin()
    {
        return MyIter(&_arr[0]);
    }
    iterator end()
    {
        //return MyIter(nullptr);
        return MyIter(&_arr[0] + _size);
    }
    int &operator[](int index)
    {
        return _arr[index];
    }

private:
    int *_arr;
    int _size;
};

int main()
{
    // for_each
    int num_arr[5] = {1, 2, 3, 4, 5};
    std::for_each(&num_arr[0], &num_arr[0] + sizeof(num_arr) / sizeof(num_arr[0]), [](int num) { std::cout << num << std::endl; });

    // iterator
    MyArr arr(5);
    arr[0] = 10;
    arr[1] = 8;
    arr[2] = 6;
    arr[3] = 4;
    arr[4] = 2;
    std::cout << arr[2] << std::endl;
    // iterator
    std::for_each(arr.begin(), arr.end(), [](int &val) { std::cout << val << std::endl; });

    return 0;
}