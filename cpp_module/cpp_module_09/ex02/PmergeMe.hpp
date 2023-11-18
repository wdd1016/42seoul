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
 public:
  PmergeMe();
  ~PmergeMe();

  typedef std::vector<int> Container;

  void fordJohnsonSort(Container &numbers, Container::iterator end,
                       size_t elementSize, size_t pairCount) {
    Container::iterator nextEnd;

    nextEnd = pairComparison(numbers, elementSize, pairCount);
    if (pairCount != 1)
      fordJohnsonSort(numbers, nextEnd, elementSize * 2, pairCount / 2);
    pendingElementInsertion(numbers, end, elementSize, pairCount);
  }

  Container::iterator pairComparison(Container &numbers, size_t elementSize,
                                     size_t pairCount) {
    Container::iterator fir = numbers.begin();
    Container::iterator sec;

    for (size_t i = 0; i < pairCount; i++) {
      sec = fir + elementSize;
      if (*fir < *sec)
        fir = std::swap_ranges(fir, sec, sec);
      else
        fir = sec + elementSize;
    }
    return fir;
  }

  void pendingElementInsertion(Container &numbers, Container::iterator end,
                               size_t elementSize, size_t pairCount) {
    Container temp;
  }
};

#endif