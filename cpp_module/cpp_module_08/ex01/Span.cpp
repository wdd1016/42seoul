#include "Span.hpp"

Span::Span() : _capacity(0) {}

Span::Span(unsigned int n) : _capacity(n) {}

Span::~Span() {}

Span::Span(const Span &src) { *this = src; }

Span &Span::operator=(const Span &src) {
  if (this == &src) return (*this);
  _capacity = src.getCapacity();
  _storage = src.getStorage();
  return (*this);
}

void Span::addNumber(int n) {
  if (_storage.size() == _capacity)
    throw std::runtime_error("Capacity is Full.");
  _storage.insert(n);
}

unsigned int Span::getCapacity() const { return _capacity; }

const std::multiset<int> &Span::getStorage() const { return _storage; }

unsigned int Span::shortestSpan() const {
  unsigned int minSpan = std::numeric_limits<unsigned int>::max();
  long long temp;

  if (_storage.size() == 0)
    throw std::runtime_error("There are no numbers stored.");
  else if (_storage.size() == 1)
    throw std::runtime_error("There is only one number stored.");
  std::multiset<int>::iterator it = _storage.begin();
  temp = *it;
  it++;
  for (; it != _storage.end(); it++) {
    if (*it - temp < minSpan) {
      minSpan = *it - temp;
      if (minSpan == 0) return minSpan;
    }
    temp = *it;
  }
  return minSpan;
}

unsigned int Span::longestSpan() const {
  if (_storage.size() == 0)
    throw std::runtime_error("There are no numbers stored.");
  else if (_storage.size() == 1)
    throw std::runtime_error("There is only one number stored.");

  return ((long long)(*_storage.rbegin()) - (*_storage.begin()));
}
