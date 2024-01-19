#include <functional>
#include <iostream>

int Func1(int a, int b, int c) { return a * 100 + b * 10 + c; }
struct SA {
  int a;
  int b;
};
template<typename T>
int Func2(const char* a, int b, float c, T& d)
{
  (void)a;
  (void)b;
  (void)c;
  (void)d;
  return (b+d.a+d.b);
}
template <typename T>
class CPub {
  public:
    CPub(T t_) : t(t_) {}
    T t;
};
template <typename TMsg>
void OnReceivePing(const char *topic_name_,
                   const TMsg &msg_,
                   const long long time_, 
                   const long long clock_,
                   const long long id_,
                   const CPub<TMsg> &pub_) {

    std::cout << " OnReceivePing "                        << std::endl;
}

class MyClass
{
  public:
    MyClass(const std::string& name) : _name(name) {}
  public:
    int OnReceive(int arg1, double arg2, void* arg) {
      std::cout << "MyClass " << _name << "(" << arg1 << "," << arg2 << ") " << *((std::string*)arg) << std::endl;
      return 0;
    }
  private:
    std::string _name;
};

int main() {
  auto func1 = std::bind(Func1, std::placeholders::_1, 0, 0);
  std::cout << func1(3) << std::endl;

  std::function<int(int)> func2 = std::bind(Func1, 1, std::placeholders::_1, 0);
  std::cout << func2(5) << std::endl;

  SA sa {9, 8};
  std::function<int(int, int)> func3 = std::bind(Func2<struct SA>, "name", std::placeholders::_2, 0.0f, sa);
  //auto func3 = std::bind(Func2, "name", std::placeholders::_1, 0.0f);
  std::cout << func3(1, 2) << std::endl;

  CPub<struct SA> pub(sa);
  std::function<void(const char* topic_name_, const struct SA& msg_, long long time_, long long clock_, long long id_)> ping_receiver = 
    std::bind(
        OnReceivePing<struct SA>,
        std::placeholders::_1,
        std::placeholders::_2,
        std::placeholders::_3,
        std::placeholders::_4,
        std::placeholders::_5,
        pub);

  std::string cb_arg = "hello!!";
  MyClass objMyClass("my_class_instance");
  std::function<int(void*)> my_callback = std::bind(&MyClass::OnReceive, &objMyClass, 1, 3.14, std::placeholders::_1);
  my_callback((void*)&cb_arg);

  return 0;
}