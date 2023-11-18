// #include "PmergeMe.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, const char *argv[]) {
  // PmergeMe mergeMe;
  std::vector<int> vec;

  (void)argc;
  (void)argv;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(9);
  vec.push_back(7);
  vec.push_back(19);
  vec.push_back(5);
  vec.push_back(22);
  vec.push_back(61);
  vec.push_back(1);
  vec.push_back(2);
  std::vector<int>::iterator fir = vec.begin();
  std::vector<int>::iterator sec = vec.begin() + 3;
  std::vector<int>::iterator end = std::swap_ranges(fir, sec, sec);
  std::cout << *end << std::endl;

  return EXIT_SUCCESS;
}