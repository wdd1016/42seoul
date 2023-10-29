#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

struct Data {
  int n;
  std::string str;
};

class Serializer {
 private:
  Serializer();
  Serializer(Serializer const &copy);
  Serializer &operator=(Serializer const &copy);

 public:
  ~Serializer();

  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif