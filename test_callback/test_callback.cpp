#include <functional>
#include <iostream>
using namespace std;

typedef std::function<int(int a, int b)> MsgReceiveCallbackT;

int adder(int a, int b) { return (a + b); }

class Adder {
public:
  int adder(int a, int b) { return (a + b); }
};

/////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {

  MsgReceiveCallbackT MyAdder =
      std::bind(adder, std::placeholders::_1, std::placeholders::_2);
  std::cout << MyAdder(1, 2) << std::endl;
  std::cout << MyAdder(5, 6) << std::endl;
  return 0;
}