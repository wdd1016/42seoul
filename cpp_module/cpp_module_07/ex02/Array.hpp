#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <ctime>
#include <exception>
#include <iostream>
#include <limits>

template <typename T>
class Array {
 private:
  T *_data;
  unsigned int _size;

 public:
  Array() : _data(NULL), _size(0) {}
  Array(unsigned int n) : _data(new T[n]), _size(n) {}
  ~Array() {
    if (_data) delete[] _data;
  }
  Array(const Array &copy) : _data(NULL), _size(0) { *this = copy; }

  Array &operator=(const Array &copy) {
    if (this == &copy) return (*this);
    if (_data) delete[] _data;
    this->_size = copy.size();
    if (_size != 0)
      this->_data = new T[_size];
    else
      this->_data = NULL;
    for (unsigned int i = 0; i < _size; i++) {
      _data[i] = (copy._data)[i];
    }
    return (*this);
  }

  T &operator[](int i) const {
    if (i < 0 ||
        _size > static_cast<unsigned int>(std::numeric_limits<int>::max()) ||
        i >= static_cast<int>(_size))
      throw std::out_of_range("This approach is out of range.");
    return _data[i];
  }

  T &operator[](unsigned int i) const {
    if (i >= _size) throw std::out_of_range("This approach is out of range.");
    return _data[i];
  }

  unsigned int size() const { return _size; }
};

#endif