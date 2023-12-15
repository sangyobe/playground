#include <iostream>
#include <string>
#include <vector>

class Person {
public:
  std::string name;
  int year;

  Person() = delete;

  Person(std::string p_name, int p_year)
      : name(std::move(p_name)), year(p_year), instance_id(instance_gen) {
    std::cout << "constructor," << name << "/" << instance_id << std::endl;
    instance_gen++;
  }

  Person(const Person &other) : name(move(other.name)), year(other.year), instance_id(instance_gen) {
    std::cout << "copy constructor," << name << "/" << instance_id << std::endl;
    instance_gen++;
  }

  //   Person(Person &&other) : name(move(other.name)), year(other.year) {
  //     std::cout << "move constructor" << std::endl;
  //   }

  ~Person() { std::cout << "destructor, " << name << "/" << instance_id << std::endl; }

  Person &operator=(const Person &other) = default;
  int instance_id;
  static int instance_gen;
};

int Person::instance_gen = 0;

int main() {
  std::vector<Person> generals;
  generals.reserve(10);
  
  std::cout << "------------------- push_back -------------------" << std::endl;
  generals.push_back(
        Person("Yi Sun-shin",
               1545)); // 복사생성자가 호출

  std::cout << "------------------- push_back(2) -------------------" << std::endl;
  generals.push_back(
        Person("Gwon Yul",
               1537)); // 복사생성자가 호출

  std::cout << "------------------- emplace_back -------------------" << std::endl;
  generals.emplace_back("Kim Yoo-Shin",
                        595); // container 내부에서 객체 생성하므로, 복사나
                               // 이동생성자가 호출되지 않는다.

  std::cout << "------------------- emplace_back(2) -------------------" << std::endl;
  generals.emplace_back("Kang Gam-Chan",
                        948);


  std::cout << "------------------- dump -------------------" << std::endl;

  for (Person const &person : generals) {
    std::cout << "Name: " << person.name << " Birth: " << person.year
              << std::endl;
  }

  return 0;
}
