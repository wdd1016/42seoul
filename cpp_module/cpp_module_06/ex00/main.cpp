#include "ScalarConverter.hpp"

int main(int argc, const char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./Convert [string]" << std::endl;
    return EXIT_FAILURE;
  }
  try {
    Scalarconverter::convert(argv[1]);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
