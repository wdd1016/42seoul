#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
  (void)src;
  return *this;
}

void PmergeMe::pendingElementsInsertion(vector &numbers, bool upFlag,
                                        size_t elemSize, size_t pairCnt) {
  std::vector<int> largerElements(elemSize * pairCnt);
  std::vector<int> pendingElements(elemSize * (pairCnt + upFlag));
  std::vector<int>::iterator numbersIt = numbers.begin();
  std::vector<int>::iterator largeIt = largerElements.begin();
  std::vector<int>::iterator pendingIt = pendingElements.begin();
  std::vector<int>::iterator tempIt;

  for (size_t i = 0; i < pairCnt; i++) {
    tempIt = numbersIt + elemSize;
    largeIt = std::copy(numbersIt, tempIt, largeIt);
    numbersIt = tempIt;
    tempIt = numbersIt + elemSize;
    pendingIt = std::copy(numbersIt, tempIt, pendingIt);
    numbersIt = tempIt;
  }
  if (upFlag) std::copy(numbersIt, numbersIt + elemSize, pendingIt);
  pendingIt = pendingElements.begin();
  while (pendingIt != pendingElements.end()) {
    tempIt = pendingIt + elemSize;
    binarySearchInsertion(largerElements, pendingIt, tempIt, elemSize);
    pendingIt = tempIt;
  }
  std::copy(largerElements.begin(), largerElements.end(), numbers.begin());
}

void PmergeMe::binarySearchInsertion(vector &lgElements, vectorIt &compIt,
                                     vectorIt &endIt, size_t elemSize) {
  std::vector<int>::iterator low = lgElements.begin();
  std::vector<int>::iterator high = lgElements.end();
  std::vector<int>::iterator mid;
  size_t halfDis;

  if (*compIt <= *low) {
    lgElements.insert(low, compIt, endIt);
    return;
  }
  while (low + elemSize < high) {
    halfDis = (std::distance(low, high) / 2);
    mid = low + halfDis - (halfDis % elemSize);
    if (*compIt >= *mid)
      low = mid;
    else
      high = mid;
  }
  lgElements.insert(high, compIt, endIt);
}

void PmergeMe::pendingElementsInsertion(list &numbers, bool upFlag,
                                        size_t elemSize, size_t pairCnt) {
  std::list<int> pendingElements;
  std::list<int> remainElements;
  std::list<int>::iterator largeIt = numbers.begin();
  std::list<int>::iterator pendingIt = pendingElements.end();
  std::list<int>::iterator tempIt;

  for (size_t i = 0; i < pairCnt; i++) {
    std::advance(largeIt, elemSize);
    tempIt = largeIt;
    std::advance(tempIt, elemSize);
    pendingElements.splice(pendingIt, numbers, largeIt, tempIt);
    largeIt = tempIt;
  }
  if (upFlag) {
    std::advance(tempIt, elemSize);
    pendingElements.splice(pendingIt, numbers, largeIt, tempIt);
    largeIt = tempIt;
  }
  remainElements.splice(remainElements.end(), numbers, largeIt, numbers.end());
  pendingIt = pendingElements.begin();
  while (pendingIt != pendingElements.end()) {
    tempIt = pendingIt;
    std::advance(tempIt, elemSize);
    binarySearchInsertion(numbers, pendingElements, pendingIt, tempIt,
                          elemSize);
    pendingIt = tempIt;
  }
  numbers.splice(numbers.end(), remainElements);
}

void PmergeMe::binarySearchInsertion(list &lgElements, list &pdElements,
                                     listIt &compIt, listIt &endIt,
                                     size_t elemSize) {
  std::list<int>::iterator low = lgElements.begin();
  std::list<int>::iterator high = lgElements.end();
  std::list<int>::iterator mid;
  size_t halfDis;

  if (*compIt <= *low) {
    lgElements.splice(low, pdElements, compIt, endIt);
    return;
  }
  while (static_cast<size_t>(std::distance(low, high)) > elemSize) {
    halfDis = (std::distance(low, high) / 2);
    mid = low;
    std::advance(mid, halfDis - (halfDis % elemSize));
    if (*compIt >= *mid)
      low = mid;
    else
      high = mid;
  }
  lgElements.splice(high, pdElements, compIt, endIt);
}

void PmergeMe::pendingElementsInsertion(deque &numbers, bool upFlag,
                                        size_t elemSize, size_t pairCnt) {
  std::deque<int> largerElements(elemSize * pairCnt);
  std::deque<int> pendingElements(elemSize * (pairCnt + upFlag));
  std::deque<int>::iterator numbersIt = numbers.begin();
  std::deque<int>::iterator largeIt = largerElements.begin();
  std::deque<int>::iterator pendingIt = pendingElements.begin();
  std::deque<int>::iterator tempIt;

  for (size_t i = 0; i < pairCnt; i++) {
    tempIt = numbersIt + elemSize;
    largeIt = std::copy(numbersIt, tempIt, largeIt);
    numbersIt = tempIt;
    tempIt = numbersIt + elemSize;
    pendingIt = std::copy(numbersIt, tempIt, pendingIt);
    numbersIt = tempIt;
  }
  if (upFlag) std::copy(numbersIt, numbersIt + elemSize, pendingIt);
  pendingIt = pendingElements.begin();
  while (pendingIt != pendingElements.end()) {
    tempIt = pendingIt + elemSize;
    binarySearchInsertion(largerElements, pendingIt, tempIt, elemSize);
    pendingIt = tempIt;
  }
  std::copy(largerElements.begin(), largerElements.end(), numbers.begin());
}

void PmergeMe::binarySearchInsertion(deque &lgElements, dequeIt &compIt,
                                     dequeIt &endIt, size_t elemSize) {
  std::deque<int>::iterator low = lgElements.begin();
  std::deque<int>::iterator high = lgElements.end();
  std::deque<int>::iterator mid;
  size_t halfDis;

  if (*compIt <= *low) {
    lgElements.insert(low, compIt, endIt);
    return;
  }
  while (low + elemSize < high) {
    halfDis = (std::distance(low, high) / 2);
    mid = low + halfDis - (halfDis % elemSize);
    if (*compIt >= *mid)
      low = mid;
    else
      high = mid;
  }
  lgElements.insert(high, compIt, endIt);
}