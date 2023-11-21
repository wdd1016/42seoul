#include <algorithm>
#include <iostream>
#include <vector>

#include "PmergeMe.hpp"

int main(int argc, const char *argv[]) {
  std::vector<int> vec;

  (void)argc;
  (void)argv;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(130);
  vec.push_back(9);
  vec.push_back(7);
  vec.push_back(19);
  vec.push_back(5);
  vec.push_back(22);
  vec.push_back(61);
  vec.push_back(1);
  vec.push_back(2);
  PmergeMe::fordfordJohnsonSort(vec);

  for (size_t i = 0; i < vec.size(); i++)
    std::cout << " " << vec[i] << std::endl;
  return EXIT_SUCCESS;
}