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
    remainedElementsInsertion(numbers, end, elementSize, pairCount);
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

  void remainedElementsInsertion(Container &numbers, Container::iterator end,
                                 size_t elementSize, size_t pairCount) {
    Container largerElements(elementSize * pairCount);
    Container remainedElements(elementSize * pairCount);
    Container::iterator numbersIt = numbers.begin();
    Container::iterator largeIt = largerElements.begin();
    Container::iterator remainIt = remainedElements.begin();
    Container::iterator tempIt;

    for (size_t i = 0; i < pairCount; i++) {
      tempIt = numbersIt + elementSize;
      largeIt = std::copy(numbersIt, tempIt, largeIt);
      numbersIt = tempIt;
      tempIt = numbersIt + elementSize;
      remainIt = std::copy(numbersIt, tempIt, remainIt);
      numbersIt = tempIt;
    }
    if (numbersIt != end)
      remainedElements.insert(remainedElements.end(), numbersIt, end);
    remainIt = remainedElements.begin();
    while (remainIt != remainedElements.end()) {
      tempIt = remainIt + elementSize;
      binarySearchInsertion(largerElements, remainIt, tempIt, elementSize);
      remainIt = tempIt;
    }
    std::copy(largerElements.begin(), largerElements.end(), numbers.begin());
  }

  void binarySearchInsertion(Container &lgElements, Container::iterator &compIt,
                             Container::iterator &endIt, size_t elementSize) {
    int compNumber = *compIt;
    size_t low = 0;
    size_t high = (lgElements.size() / elementSize) - 1;
    size_t mid;

    if (compNumber <= lgElements[0]) {
      lgElements.insert(lgElements.begin(), compIt, endIt);
      return;
    }
    while (low <= high) {
      mid = (low + high / 2);
      if (compNumber > lgElements[mid * elementSize])
        high = mid - 1;
      else {
        lgElements.insert(lgElements.begin() + mid * elementSize, compIt,
                          endIt);
        return;
      }
    }
  }
};

#endif