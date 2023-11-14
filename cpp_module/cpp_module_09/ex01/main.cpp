#include "RPN.hpp"

int main(int argc, const char *argv[]) {
  RPN rpn;

  if (argc != 2) {
    std::cerr << "Error -> USAGE : ./RPN formula" << std::endl;
    return EXIT_FAILURE;
  }
  rpn.calculation(argv[1]);
  return EXIT_SUCCESS;
}
