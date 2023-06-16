#include <iostream>
#include <list>
#include <map>
#include <string>

template <typename KType, typename CType> class SortedList {
public:
  class Cont {
  public:
    Cont(KType k, CType v) : m_key(k), m_value(v) {}
    void Print() {
      std::cout << "(" << m_key << ", " << m_value << ")" << std::endl;
    }
    KType key() const { return m_key; }
    CType value() const { return m_value; }

    bool operator<(Cont &rhs) { return (m_key < rhs.key()); }
    bool operator<=(Cont &rhs) { return (m_key <= rhs.key()); }
    bool operator==(Cont &rhs) { return (m_key == rhs.key()); }
    bool operator>(Cont &rhs) { return (m_key > rhs.key()); }
    bool operator>=(Cont &rhs) { return (m_key >= rhs.key()); }

    bool operator<(KType &key) { return (m_key < key); }

  private:
    KType m_key;
    CType m_value;
  };

  void Add(KType key, CType val) {
    Cont cont(key, val);

    typename std::list<Cont>::iterator itr = m_list.begin();
    while (itr != m_list.end()) {
      if ((*itr) > cont) {
        // insert before
        m_list.insert(itr, cont);
        return;
      }
      itr++;
    }
    m_list.push_back(cont);
  }

  void Clear() { m_list.clear(); }
  void Dump() {
    typename std::list<Cont>::iterator itr = m_list.begin();
    while (itr != m_list.end()) {
      (*itr).Print();
      itr++;
    }
  }

  void GetHighest(KType index, CType &value) {
    KType key = 0;

    typename std::list<Cont>::iterator itr = m_list.begin();

    if (itr != m_list.end())
      value = (*itr).value();

    while (itr != m_list.end()) {
      if ((*itr) < index) {
        value = (*itr).value();
      } else {
        break;
      }
      itr++;
    }
  }

private:
  std::list<Cont> m_list;
};

int main() {
  SortedList<double, std::string> myList;
  myList.Add(1.0, "A");
  myList.Add(3.0, "B");
  myList.Add(7.0, "C");
  myList.Add(9.0, "D");
  myList.Add(10.0, "E");
  myList.Add(5.0, "X");
  myList.Add(-1.0, "XX");
  myList.Dump();

  std::string result;
  double search_key = -5;
  myList.GetHighest(search_key, result);
  std::cout << "name at (" << search_key << ") = " << result << std::endl;

  search_key = 4;
  myList.GetHighest(search_key, result);
  std::cout << "name at (" << search_key << ") = " << result << std::endl;

  search_key = 15;
  myList.GetHighest(search_key, result);
  std::cout << "name at (" << search_key << ") = " << result << std::endl;

  return 0;
}