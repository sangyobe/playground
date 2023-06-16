#include <iostream>
#include <string>
#include <vector>

class Person {
public:
  std::string name;
  int year;

  Person(std::string p_name, int p_year)
      : name(std::move(p_name)), year(p_year) {
    std::cout << "constructor" << std::endl;
  }

  Person(const Person &other) : name(move(other.name)), year(other.year) {
    std::cout << "copy constructor" << std::endl;
  }

  //   Person(Person &&other) : name(move(other.name)), year(other.year) {
  //     std::cout << "move constructor" << std::endl;
  //   }

  ~Person() { std::cout << "destructor" << std::endl; }

  Person &operator=(const Person &other) = default;
};

int main() {
  std::vector<Person> generals;
  //   generals.push_back(
  //       Person("Yi Sun-shin",
  //              1545)); // move or copy ?? 이동생성자가 정의되지 않았다면,
  //              대신
  //                      // 복사생성자가 호출(속도면에서 이동생성자가 빠르다.)

  generals.emplace_back("Yi Sun-shin",
                        1545); // container 내부에서 객체 생성하므로, 복사나
                               // 이동생성자가 호출되지 않는다.

  for (Person const &person : generals) {
    std::cout << "Name: " << person.name << " Birth: " << person.year
              << std::endl;
  }

  return 0;
}
