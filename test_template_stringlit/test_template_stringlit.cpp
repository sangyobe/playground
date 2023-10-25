#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class Foo
{
public:
    Foo(const T& data) : data(data)
    { }
    
    T data;
};

int main()
{
    // c++14
    Foo<int> a = 42;
    auto f = Foo<int>{ a.data };
    // c++17
    // Foo a = 42;
    // auto f = Foo{ a.data };
    cout << f.data << endl;

    return 0;
}

// /**
//  * Literal class type that wraps a constant expression string.
//  *
//  * Uses implicit conversion to allow templates to *seemingly* accept constant strings.
//  */
// template<size_t N>
// struct StringLiteral {
//     constexpr StringLiteral(const char (&str)[N]) {
//         std::copy_n(str, N, value);
//     }
    
//     char value[N];
// };

// // template<StringLiteral lit>
// // void Print() {
// //     // The size of the string is available as a constant expression.
// //     constexpr auto size = sizeof(lit.value);

// //     // and so is the string's content.
// //     constexpr auto contents = lit.value;

// //     std::cout << "Size: " << size << ", Contents: " << contents << std::endl;
// // }

// int main()
// {
//     //Print<"literal string">(); // Prints "Size: 15, Contents: literal string"
//     StringLiteral lit("hello");
//     std::cout << "Size: " << sizeof(lit.value) << std::endl;
// }