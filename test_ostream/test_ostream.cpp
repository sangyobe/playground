#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person
{
public:
    string name;
    uint16_t age;

private:
    // Overloading stream insertion operators
    // 1. These operators must be overloaded as a global function.
    // 2. These operators must be friend of this class to access its private members.
    //
    friend ostream& operator<<(ostream& out, const Person& rhs) {
        out << rhs.name << " " << rhs.age << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Person& rhs) {
        in >> rhs.name >> rhs.age;
        return in;
    }
};

int main()
{
    fstream out("test_ostream.txt", ios::out | ios::binary);
    out << "hello world" << endl;

    Person sean;
    sean.name = "Sean_Yi";
    sean.age  = 40;

    out << sean;

    fstream in("test_ostream.txt", ios::in | ios::binary);
    std::string hello, world;
    in >> hello;
    in >> world;

    cout << hello << endl;
    cout << world << endl;

    Person sean2;
    in >> sean2;
    cout << sean2.name << " " << sean2.age << endl;

    return 0;
}