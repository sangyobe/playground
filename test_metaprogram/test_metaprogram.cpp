#include <iostream>

//////////////////////////////////////////////////////////////////////
//
// calculate Factorial(N)
//
template <int N>
class Fact
{
public:
  enum { value = Fact<N-1>::value * N };
};

template <>
class Fact<1>
{
public:
  enum { value = 1 };
};

//////////////////////////////////////////////////////////////////////
//
// calculate SquareRoot(N)
//
template <int N, int LO=1, int HI=N>
class Sqrt 
{
public:
  enum { mid = (int)((LO+HI+1)/2) };
  enum { result = (N<mid*mid) ? (int)(Sqrt<N,LO, (int)mid-1>::result)
                              : (int)(Sqrt<N,(int)mid,HI>::result) };
};

template <int N, int M>
class Sqrt<N,M,M> {
public:
  enum { result = M };
};

//////////////////////////////////////////////////////////////////////
//
// calculate SquareRoot(N) - 2nd
//
template <bool C, typename Ta, typename Tb>
class IfThenElse;

template <typename Ta, typename Tb>
class IfThenElse<true, Ta, Tb>
{
public:
  typedef Ta type;
};

template <typename Ta, typename Tb>
class IfThenElse<false, Ta, Tb>
{
public:
  typedef Tb type;
};

template <int N, int LO=1, int HI=N>
class Sqrt2 
{
public:
  enum { mid = (int)((LO+HI+1)/2) };
  typedef typename IfThenElse<(N<mid*mid), Sqrt2<N,LO, (int)mid-1>, Sqrt2<N,(int)mid,HI>>::type SubT;
  enum { result = SubT::result };
};

template <int N, int M>
class Sqrt2<N,M,M> {
public:
  enum { result = M };
};

//////////////////////////////////////////////////////////////////////
//
// calculate SquareRoot(N) - 3rd
//
template <int N>
class Value
{
public:
  enum { result = N };
};

template <int N, int I=1>
class Sqrt3 
{
public:
  typedef typename IfThenElse<(I*I<N), Sqrt3<N,I+1>, Value<I>>::type SubT;
  enum { result = SubT::result };
};

template <int N>
class Sqrt3<N,N> {
public:
  enum { result = N };
};

//////////////////////////////////////////////////////////////////////
//
// calculate dot product of two vectors
//
template <int DIM, typename T>
class DotProduct
{
public:
  static T result (T* a, T*  b) {
    return *a * *b + DotProduct<DIM-1, T>::result(a+1, b+1);
  }
};

template <typename T>
class DotProduct<1, T>
{
public:
  static T result (T* a, T*  b) {
    return *a * *b;
  }
};

template <int DIM, typename T>
inline T dot_product(T* a, T* b)
{
  return DotProduct<DIM, T>::result(a, b);
}


int main() {
  std::cout << "3! = " << Fact<3>::value << std::endl;
  std::cout << "5! = " << Fact<5>::value << std::endl;

  std::cout << "sqrt(9) = " << Sqrt<9>::result << std::endl;
  std::cout << "sqrt(25) = " << Sqrt<25>::result << std::endl;
  std::cout << "sqrt(30) = " << Sqrt<30>::result << std::endl;

  std::cout << "sqrt(9) = " << Sqrt2<9>::result << std::endl;
  std::cout << "sqrt(25) = " << Sqrt2<25>::result << std::endl;
  std::cout << "sqrt(30) = " << Sqrt2<30>::result << std::endl;

  std::cout << "sqrt(9) = " << Sqrt3<9>::result << std::endl;
  std::cout << "sqrt(25) = " << Sqrt3<25>::result << std::endl;
  std::cout << "sqrt(30) = " << Sqrt3<30>::result << std::endl;

  int a[3] = {1, 2, 3};
  int b[3] = {5, 6, 7};
  std::cout << "dot_product(a, b) = " << dot_product<3, int>(a, b) << std::endl;

  return 0;
}