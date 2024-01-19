#include <iostream>
#include <type_traits> // std::type_traits

template <typename T>
struct is_pointer
{
    static constexpr bool value = false;
};

template <typename T>
struct is_pointer<T*>
{
    static constexpr bool value = true;
};

template <typename T>
void print1(T t)
{
    if constexpr(is_pointer<T>::value)
        std::cout << *t << std::endl;
    else
        std::cout << t << std::endl;
}

template <typename T>
struct is_void
{
    static constexpr bool value = false;
};

template <>
struct is_void<void>
{
    static constexpr bool value = true;
};


template <typename T>
void only_integer(const T& t) {
    static_assert(std::is_integral<T>::value, "only integer argument can be feed.");
}

int main()
{
    std::string hello = "hello world";
    double pi = 3.14;
    print1(hello);
    print1(&hello);
    print1(1);
    print1(pi);
    print1(&pi);

    std::cout << "int is " << (is_void<int>::value ? "void" : "not void") << std::endl; 
    std::cout << "void is " << (is_void<void>::value ? "void" : "not void") << std::endl; 

    only_integer(10);
    // only_integer(pi);

    return 0;
}



