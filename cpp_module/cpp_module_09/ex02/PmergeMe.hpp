#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <sstream>
#include <utility>
#include <vector>

typedef std::vector<unsigned int> vector;
typedef std::list<unsigned int> list;
typedef std::deque<unsigned int> deque;
typedef std::vector<unsigned int>::iterator vectorIt;
typedef std::list<unsigned int>::iterator listIt;
typedef std::deque<unsigned int>::iterator dequeIt;

class PmergeMe {
 private:
  static vector _vec;
  static list _lst;
  static deque _deq;

  PmergeMe();
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &src);

  static void validationTransformContainers(int argc, const char *argv[]);

  template <typename Container>
  static clock_t playFordJohnsonCountTime(Container &container) {
    clock_t temp;

    temp = clock();
    fordJohnsonRecursion(container, 1, container.size() / 2);
    return (clock() - temp);
  }

  template <typename Container>
  static void fordJohnsonRecursion(Container &numbers, size_t elementSize,
                                   size_t pairCount) {
    bool unpairedFlag;

    // Pair 내부 비교 -> 큰 순으로 배열, Pair을 없는 element가 있는지 확인
    unpairedFlag = pairComparison(numbers, elementSize, pairCount);
    // Pair가 하나가 될때까지 재귀적 반복
    if (pairCount != 1)
      fordJohnsonRecursion(numbers, elementSize * 2, pairCount / 2);
    // Binary Search를 이용한 Insertion
    pendingElementsInsertion(numbers, unpairedFlag, elementSize, pairCount);
  }

  static bool pairComparison(vector &numbers, size_t elementSize,
                             size_t pairCount);
  static void pendingElementsInsertion(vector &numbers, bool upFlag,
                                       size_t elemSize, size_t pairCnt);
  static void binarySearchInsertion(vector &lgElements, vector &pdElement,
                                    size_t elemSize);

  static bool pairComparison(list &numbers, size_t elementSize,
                             size_t pairCount);
  static void pendingElementsInsertion(list &numbers, bool upFlag,
                                       size_t elemSize, size_t pairCnt);
  static void binarySearchInsertion(list &lgElements, list &pdElements,
                                    size_t elemSize);

  static bool pairComparison(deque &numbers, size_t elementSize,
                             size_t pairCount);
  static void pendingElementsInsertion(deque &numbers, bool upFlag,
                                       size_t elemSize, size_t pairCnt);
  static void binarySearchInsertion(deque &lgElements, deque &pdElement,
                                    size_t elemSize);

 public:
  ~PmergeMe();

  static void fordJohnsonSort(int argc, const char *argv[]);
};

#endif