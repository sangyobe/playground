#include <iostream>
using namespace std;

template <typename T> class Base {
  T asset;

public:
  Base(T a) { asset = a; }
  void showAsset() { cout << asset << endl; }
  void getMoney(T a) { asset += a; }
};

template <typename U> class Derived : public Base<U> {
  U money;

public:
  Derived(U a, U b) : Base<U>(a) { money = b; }
  void exchange() {
    this->getMoney(money);
    money = 0;
  }
};

void example1() {
  Derived<int> ID(5000, 1000);
  Derived<double> DD(200.78, 107.50);

  ID.exchange();
  ID.showAsset();

  DD.exchange();
  DD.showAsset();
}

/////////////////////////////////////////////////////////////////////
template <typename T, int K> struct A {
  void a(T);
  void b(T);
  void z(T);
};

template <typename T, int K> void A<T, K>::a(T) {
  cout << "A<T, K>::a(T)" << endl;
}

template <typename T, int K> void A<T, K>::b(T) {}

template <typename T, int K> void A<T, K>::z(T) {}

// explicit full specialization of a memeber function
template <> void A<int, 1>::a(int) {
  // do something special for this particular template parameter
  cout << "A<int, 1>::a(T)" << endl;
}
// explicit partial specialization of a memeber function
//
// !!! You cannot partially specialize only a single member function, you must
// partially specialize the whole class.
//
// template <typename T> void A<T, 1>::a(T) {
//   // do something special for this particular template parameter
//   cout << "A<T, 1>::a(T)" << endl;
// }

void example2() {
  A<double, 2> ad2;
  ad2.a(3.0);

  A<int, 1> ai1;
  ai1.a(3.0);
}

/////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {

  example1();
  example2();

  return 0;
}