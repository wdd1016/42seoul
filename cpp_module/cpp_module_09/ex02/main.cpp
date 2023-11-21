#include "PmergeMe.hpp"

int main(int argc, const char *argv[]) {
  std::vector<int> vec;
  std::list<int> lst;
  std::deque<int> deq;

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

  for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    std::cout << *it << std::endl;
  return EXIT_SUCCESS;
}