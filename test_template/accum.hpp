#ifndef ACCUM_HPP
#define ACCUM_HPP

class SumPolicy {
public:
  template <typename T1, typename T2>
  static void accum(T1 &total, T2 const &value) {
    total += value;
  }
};

class MultPolicy {
public:
  template <typename T1, typename T2>
  static void accum(T1 &total, T2 const &value) {
    total *= value;
  }
};

template <typename T> class AccumTraits;

template <> class AccumTraits<char> {
public:
  typedef unsigned int AccT;
  static AccT zero() { return 0; }
};

template <> class AccumTraits<short> {
public:
  typedef int AccT;
  static AccT zero() { return 0; }
};

template <> class AccumTraits<unsigned short> {
public:
  typedef unsigned int AccT;
  static AccT zero() { return 0; }
};

template <> class AccumTraits<int> {
public:
  typedef long AccT;
  static AccT zero() { return 0; }
};

template <> class AccumTraits<unsigned int> {
public:
  typedef unsigned long AccT;
  static AccT zero() { return 0; }
};

template <> class AccumTraits<float> {
public:
  typedef float AccT;
  static AccT zero() { return 0.0f; }
};

template <> class AccumTraits<double> {
public:
  typedef double AccT;
  static AccT zero() { return 0.0; }
};

template <typename T, typename Policy = SumPolicy,
          typename Traits = AccumTraits<T>>
class Accum {
public:
  static typename Traits::AccT accum(T const *begin, T const *end) {
    typename Traits::AccT total = Traits::zero();
    while (begin != end) {
      Policy::accum(total, *begin);
      begin++;
    }
    return total;
  }
};

#endif