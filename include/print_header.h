#ifndef _PRINT_HELPER_H_
#define _PRINT_HELPER_H_

#include <iostream>

inline void PrintTestHeader(char const *name) {
  std::cout << "==========================================" << std::endl;
  std::cout << " " << name << std::endl;
  std::cout << "------------------------------------------" << std::endl;
}

#endif // _PRINT_HELPER_H_