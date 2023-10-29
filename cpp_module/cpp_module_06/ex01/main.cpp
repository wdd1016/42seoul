#include "Serializer.hpp"

int main() {
  Data *data = new Data;

  data->n = 42;
  data->str = "Hello, world!";
  std::cout << "We have a data" << std::endl;
  std::cout << "data->n : " << data->n << std::endl;
  std::cout << "data->str : " << data->str << std::endl;
  std::cout << "------------------------------------------" << std::endl;

  uintptr_t raw = Serializer::serialize(data);
  std::cout << "We serialize data, output is raw" << std::endl;
  std::cout << "raw : " << raw << std::endl;
  std::cout << "------------------------------------------" << std::endl;

  Data *data2 = Serializer::deserialize(raw);
  std::cout << "We deserialize raw, output is data2" << std::endl;
  std::cout << "data2->n : " << data2->n << std::endl;
  std::cout << "data2->str : " << data2->str << std::endl;
  std::cout << "------------------------------------------" << std::endl;

  std::cout << "If we change data->n to 21, data2->n will change too"
            << std::endl;
  data->n = 21;
  std::cout << "data->n : " << data->n << std::endl;
  std::cout << "data2->n : " << data2->n << std::endl;

  delete data;

  return 0;
}