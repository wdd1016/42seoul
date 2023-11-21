#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::pendingElementsInsertion(std::vector<int> &numbers,
                                        bool unpairedFlag, size_t elementSize,
                                        size_t pairCount) {
  std::vector<int> largerElements(elementSize * pairCount);
  std::vector<int> pendingElements(elementSize * (pairCount + unpairedFlag));
  std::vector<int>::iterator numbersIt = numbers.begin();
  std::vector<int>::iterator largeIt = largerElements.begin();
  std::vector<int>::iterator pendingIt = pendingElements.begin();
  std::vector<int>::iterator tempIt;

  for (size_t i = 0; i < pairCount; i++) {
    tempIt = numbersIt + elementSize;
    largeIt = std::copy(numbersIt, tempIt, largeIt);
    numbersIt = tempIt;
    tempIt = numbersIt + elementSize;
    pendingIt = std::copy(numbersIt, tempIt, pendingIt);
    numbersIt = tempIt;
  }
  if (unpairedFlag) std::copy(numbersIt, numbersIt + elementSize, pendingIt);
  pendingIt = pendingElements.begin();
  while (pendingIt != pendingElements.end()) {
    tempIt = pendingIt + elementSize;
    binarySearchInsertion(largerElements, pendingIt, tempIt, elementSize);
    pendingIt = tempIt;
  }
  std::copy(largerElements.begin(), largerElements.end(), numbers.begin());
}