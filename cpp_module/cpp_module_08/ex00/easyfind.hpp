#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int needle) {
  typename T::iterator it;

  for (it = container.begin(); it != container.end(); it++) {
    if (*it == needle) return it;
  }
  throw std::runtime_error("Not found.");
  return it;
}

#endif