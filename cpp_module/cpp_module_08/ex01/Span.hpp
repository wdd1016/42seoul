#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

class Span {
 private:
  std::multiset<int> _storage;
  unsigned int _capacity;

  Span();

 public:
  ~Span();
  Span(unsigned int n);
  Span(const Span &src);
  Span &operator=(const Span &src);

  void addNumber(int n);
  template <typename T>
  void addNumbers(T start, T end) {
    if (std::distance(start, end) <= 0) {
      throw std::runtime_error("Invaild Argument.");
    } else if (static_cast<size_t>(std::distance(start, end)) >
               _capacity - _storage.size()) {
      throw std::runtime_error("Not Enough Capacity.");
    }
    _storage.insert(start, end);
  }
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;
  unsigned int getCapacity() const;
  const std::multiset<int> &getStorage() const;
};

#endif