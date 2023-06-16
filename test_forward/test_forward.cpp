#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

struct Person {
  string name;
  int *year = nullptr;

  Person() {}

  Person(string p_name, const int p_year)
      : name(move(p_name)), year(new int(p_year)) {
    cout << "constructed" << endl;
  }

  Person(const Person &other) noexcept
      : name(move(other.name)), year(new int(*other.year)) {
    cout << "copy constructed" << endl;
  }

  void Print() { cout << "Name: " << name << " Birth: " << *year << endl; }

  Person(Person &&other) noexcept : name(move(other.name)), year(nullptr) {
    // Rvalue의 힙에서 할당된 year를 이동시킵니다.
    year = other.year;
    // Rvalue의 year를 nullptr 초기화 시킵니다.
    other.year = nullptr;

    cout << "move constructed" << endl;
  }

  Person &operator=(const Person &other) noexcept {
    if (this != &other) {
      this->name = other.name;
      this->year = new int(*other.year);
    }
    cout << "copy Assignment operator" << endl;
    return *this;
  }

  Person &operator=(Person &&other) noexcept {
    if (this != &other) {
      this->name = std::move(other.name);

      if (this->year)
        delete this->year;

      this->year = other.year;
      other.year = nullptr;
    }
    cout << "move Assignment operator" << endl;
    return *this;
  }

  virtual ~Person() {
    if (nullptr != year) {
      delete year;
    }
    cout << "destructed " << endl;
  }
};

// lvalue를 캐치하는 함수
void Catch(Person &p, const char *name) {
  cout << name << "lvalue catch" << endl;
}

// rvalue를 캐치하는 함수
void Catch(Person &&p, const char *name) {
  cout << name << "rvalue catch" << endl;
}

// 전달받은 obj를 std::forward를 통해서 catch 함수로 전달합니다.
template <typename T> void ForwardingObj(T &&obj, const char *name) {
  Catch(std::forward<T>(obj), name);
}

int main(int argc, char *argv[]) {
  Person p1("ahn", 1985);
  p1.Print();
  ForwardingObj(p1, "p1\t\t=\t");
  p1.Print();
  ForwardingObj(std::move(p1), "std::move(p1)\t=\t");
  p1.Print();

  return 0;
}