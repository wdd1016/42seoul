#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <utility>
#include <vector>

typedef std::vector<int> vector;
typedef std::list<int> list;
typedef std::deque<int> deque;
typedef std::vector<int>::iterator vectorIt;
typedef std::list<int>::iterator listIt;
typedef std::deque<int>::iterator dequeIt;

class PmergeMe {
 private:
  PmergeMe();
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &src);

  template <typename Container>
  static void fordJohnsonRecursion(Container &numbers, size_t elementSize,
                                   size_t pairCount) {
    typename Container::iterator fir = numbers.begin();
    typename Container::iterator sec;
    bool unpairedFlag = false;

    // Pair 내부의 앞을 비교하여 큰 순으로 배열
    for (size_t i = 0; i < pairCount; i++) {
      sec = fir;
      std::advance(sec, elementSize);
      if (*fir < *sec)
        fir = std::swap_ranges(fir, sec, sec);
      else {
        fir = sec;
        std::advance(fir, elementSize);
      }
    }
    // Pair을 이루지 못한 수가 있는지 확인
    if (static_cast<size_t>(std::distance(fir, numbers.end())) >= elementSize)
      unpairedFlag = true;
    // Pair가 하나가 될때까지 재귀적 반복
    if (pairCount != 1)
      fordJohnsonRecursion(numbers, elementSize * 2, pairCount / 2);
    // Binary Search를 이용한 Insertion
    pendingElementsInsertion(numbers, unpairedFlag, elementSize, pairCount);
  }

  static void pendingElementsInsertion(vector &numbers, bool upFlag,
                                       size_t elemSize, size_t pairCnt);
  static void binarySearchInsertion(vector &lgElements, vectorIt &compIt,
                                    vectorIt &endIt, size_t elemSize);

  static void pendingElementsInsertion(list &numbers, bool upFlag,
                                       size_t elemSize, size_t pairCnt);
  static void binarySearchInsertion(list &lgElements, list &pdElements,
                                    listIt &compIt, listIt &endIt,
                                    size_t elemSize);

  static void pendingElementsInsertion(deque &numbers, bool upFlag,
                                       size_t elemSize, size_t pairCnt);
  static void binarySearchInsertion(deque &lgElements, dequeIt &compIt,
                                    dequeIt &endIt, size_t elemSize);

 public:
  ~PmergeMe();

  template <typename Container>
  static void fordfordJohnsonSort(Container &numbers) {
    fordJohnsonRecursion(numbers, 1, numbers.size() / 2);
  }
};

#endif