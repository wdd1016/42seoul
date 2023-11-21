#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <utility>
#include <vector>

class PmergeMe {
 private:
  PmergeMe();

  template <typename Container>
  static void fordJohnsonRecursion(Container &numbers, size_t elementSize,
                                   size_t pairCount) {
    bool unpairedFlag;

    unpairedFlag = pairComparison(numbers, elementSize, pairCount);
    if (pairCount != 1)
      fordJohnsonRecursion(numbers, elementSize * 2, pairCount / 2);
    pendingElementsInsertion(numbers, unpairedFlag, elementSize, pairCount);
  }
  template <typename Container>
  static bool pairComparison(Container &numbers, size_t elementSize,
                             size_t pairCount) {
    typename Container::iterator fir = numbers.begin();
    typename Container::iterator sec;

    for (size_t i = 0; i < pairCount; i++) {
      sec = fir + elementSize;
      if (*fir < *sec)
        fir = std::swap_ranges(fir, sec, sec);
      else
        fir = sec + elementSize;
    }
    if (static_cast<size_t>(std::distance(fir, numbers.end())) >= elementSize)
      return true;
    else
      return false;
  }
  static void pendingElementsInsertion(std::vector<int> &numbers,
                                       bool unpairedFlag, size_t elementSize,
                                       size_t pairCount);
  static void pendingElementsInsertion(std::list<int> &numbers,
                                       bool unpairedFlag, size_t elementSize,
                                       size_t pairCount);
  static void pendingElementsInsertion(std::deque<int> &numbers,
                                       bool unpairedFlag, size_t elementSize,
                                       size_t pairCount);

  static void binarySearchInsertion(std::vector<int> &lgElements,
                                    std::vector<int>::iterator &compIt,
                                    std::vector<int>::iterator &endIt,
                                    size_t elementSize) {
    std::vector<int>::iterator low = lgElements.begin();
    std::vector<int>::iterator high = lgElements.end();
    std::vector<int>::iterator mid;
    size_t distance;

    if (*compIt <= *low) {
      lgElements.insert(low, compIt, endIt);
      return;
    }
    while (low + elementSize < high) {
      distance = (std::distance(low, high) / 2);
      distance = distance - (distance % elementSize);
      mid = low + distance;
      if (*compIt >= *mid)
        low = mid;
      else
        high = mid;
    }
    lgElements.insert(high, compIt, endIt);
  }

 public:
  ~PmergeMe();

  template <typename Container>
  static void fordfordJohnsonSort(Container &numbers) {
    fordJohnsonRecursion(numbers, 1, numbers.size() / 2);
  }
};

#endif