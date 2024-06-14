#include <algorithm>
#include <iostream>

int main()
{
    // for_each
    int num_arr[5] = {1, 2, 3, 4, 5};
    std::for_each(&num_arr[0], &num_arr[0] + sizeof(num_arr) / sizeof(num_arr[0]), [](int num) { std::cout << num << std::endl; });

    return 0;
}