#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &copy) { *this = copy; }

Serializer &Serializer::operator=(Serializer const &copy) {
  if (this != &copy) {
    return *this;
  }
  return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}
