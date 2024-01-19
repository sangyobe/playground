
#include <iostream>
#include <string_view>

int main(int argc, char *argv[]) {
  std::string_view sv1("123456789");
  std::copy(sv1.begin(), sv1.end(), std::ostreambuf_iterator<char>(std::cout));
  std::cout << std::endl;

  std::cout << sv1.data() << std::endl;

  std::string_view sv2("123456789", 2);
  std::copy(sv2.begin(), sv2.end(), std::ostreambuf_iterator<char>(std::cout));
  std::cout << std::endl;

  std::cout << sv2.data() << std::endl;

  return 0;
}