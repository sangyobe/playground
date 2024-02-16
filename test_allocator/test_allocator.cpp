#include <cstdlib>
#include <iostream>
#include <limits>
#include <new>
#include <vector>
#include <list>
#include <memory>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  /**
   *  @addtogroup allocators
   *  @{
   */

  /// allocator<void> specialization.
  template<>
    class allocator<std::string>
    {
    public:
      typedef size_t      size_type;
      typedef ptrdiff_t   difference_type;
      typedef void*       pointer;
      typedef const void* const_pointer;
      typedef void        value_type;

      template<typename _Tp1>
	struct rebind
	{ typedef allocator<_Tp1> other; };

#if __cplusplus >= 201103L
      // _GLIBCXX_RESOLVE_LIB_DEFECTS
      // 2103. std::allocator propagate_on_container_move_assignment
      typedef true_type propagate_on_container_move_assignment;

      typedef true_type is_always_equal;

      template<typename _Up, typename... _Args>
	void
	construct(_Up* __p, _Args&&... __args)
	noexcept(std::is_nothrow_constructible<_Up, _Args...>::value)
	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }

      template<typename _Up>
	void
	destroy(_Up* __p)
	noexcept(std::is_nothrow_destructible<_Up>::value)
	{ __p->~_Up(); }
#endif
    };
}


template <class T> struct Mallocator {
  typedef T value_type;

  Mallocator() = default;

  template <class U> constexpr Mallocator(const Mallocator<U> &) noexcept {}

  [[nodiscard]] T *allocate(std::size_t n) {
    if (n > std::numeric_limits<std::size_t>::max() / sizeof(T))
      throw std::bad_array_new_length();

    if (auto p = static_cast<T *>(std::malloc(n * sizeof(T)))) {
      report(p, n);
      return p;
    }

    throw std::bad_alloc();
  }

  void deallocate(T *p, std::size_t n) noexcept {
    report(p, n, 0);
    std::free(p);
  }

private:
  void report(T *p, std::size_t n, bool alloc = true) const {
    std::cout << (alloc ? "Alloc: " : "Dealloc: ") << sizeof(T) * n
              << " bytes at " << std::hex << std::showbase
              << reinterpret_cast<void *>(p) << std::dec << '\n';
  }
};

template <class T, class U>
bool operator==(const Mallocator<T> &, const Mallocator<U> &) {
  return true;
}

template <class T, class U>
bool operator!=(const Mallocator<T> &, const Mallocator<U> &) {
  return false;
}

int main() {
  std::vector<int, Mallocator<int>> v(8);
  v.push_back(42);

  std::list<std::string, Mallocator<std::string>> str_list;
  str_list.push_back(std::string("12345"));
  str_list.emplace_back(std::string("1234567890"));
}