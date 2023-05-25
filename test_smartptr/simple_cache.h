#ifndef __SIMPLE_CACHE_H__
#define __SIMPLE_CACHE_H__

#include <iostream>
#include <map>
#include <memory>
#include <string>

template <typename T> class SimpleCache {
public:
  SimpleCache() = default;
  ~SimpleCache() = default;

  void Add(std::string key, std::weak_ptr<T> ptr) {
    auto it = _map.find(key);
    if (it == _map.end()) {
      _map.insert(std::pair<std::string, std::weak_ptr<T>>(key, ptr));
      return;
    }
    _map[key] = ptr;
  }
  std::shared_ptr<T> Get(std::string key) {
    auto it = _map.find(key);
    if (it == _map.end()) {
      return std::shared_ptr<T>();
    }
    if (it->second.expired()) {
      _map.erase(it);
      return std::shared_ptr<T>();
    }
    return it->second.lock();
  }

private:
  std::map<std::string, std::weak_ptr<T>> _map;
};

#endif // __SIMPLE_CACHE_H__