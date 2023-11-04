#include "iter.hpp"

template <typename T>
void print(T &something) {
  std::cout << something << " ";
}

int main() {
  char chars[] = {'a', 'b', 'c', 'd', 'e'};
  int ints[] = {1, 2, 3, 4, 5};
  float floats[] = {1.1, 2.1, 3.1, 4.1, 5.1};

  std::cout << "we run iter(chars, 5, print<const char>)" << std::endl;
  iter(chars, 5, print<const char>);
  std::cout << std::endl << std::endl;

  std::cout << "we run iter(chars, 5, print<char>)" << std::endl;
  iter(chars, 5, print<char>);
  std::cout << std::endl << std::endl;

  std::cout << "we run iter(ints, 5, print<const int>)" << std::endl;
  iter(ints, 5, print<const int>);
  std::cout << std::endl << std::endl;

  std::cout << "we run iter(ints, 5, print<int>)" << std::endl;
  iter(ints, 5, print<int>);
  std::cout << std::endl << std::endl;

  std::cout << "we run iter(ints, 5, print<const float>)" << std::endl;
  iter(floats, 5, print<const float>);
  std::cout << std::endl << std::endl;

  std::cout << "we run iter(ints, 5, print<float>)" << std::endl;
  iter(floats, 5, print<float>);
  std::cout << std::endl;

  return 0;
}