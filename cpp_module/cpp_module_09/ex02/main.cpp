#include "PmergeMe.hpp"

int main(int argc, const char *argv[]) {
  if (argc == 1) {
    std::cout << "Error" << std::endl;
    return EXIT_FAILURE;
  }
  try {
    PmergeMe::fordJohnsonSort(argc, argv);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}