#include "PmergeMe.hpp"

vector PmergeMe::_vec;
list PmergeMe::_lst;
deque PmergeMe::_deq;

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
  (void)src;
  return *this;
}

void PmergeMe::fordJohnsonSort(int argc, const char *argv[]) {
  clock_t vecTime;
  clock_t lstTime;
  clock_t deqTime;

  validationTransformContainers(argc, argv);
  std::cout << "Before:";
  for (size_t i = 0; i < _vec.size(); i++) std::cout << " " << _vec[i];
  std::cout << std::endl;

  vecTime = playFordJohnsonCountTime(_vec);
  lstTime = playFordJohnsonCountTime(_lst);
  deqTime = playFordJohnsonCountTime(_deq);

  std::cout << "After:";
  for (size_t i = 0; i < _vec.size(); i++) std::cout << " " << _vec[i];
  std::cout << std::endl;
  std::cout << "Time to process a range of " << _vec.size()
            << " elements with std::vector : " << vecTime << " us" << std::endl;
  std::cout << "Time to process a range of " << _lst.size()
            << " elements with std::list : " << lstTime << " us" << std::endl;
  std::cout << "Time to process a range of " << _deq.size()
            << " elements with std::deque : " << deqTime << " us" << std::endl;
}

void PmergeMe::validationTransformContainers(int argc, const char *argv[]) {
  std::string temp;
  unsigned long num;
  char *str_end;

  for (int i = 1; i < argc; i++) {
    std::stringstream ss(argv[i]);

    while (ss >> temp) {
      errno = 0;
      num = std::strtoul(temp.c_str(), &str_end, 10);
      if (*str_end != '\0')
        throw std::runtime_error("Non-numeric Argument Error");

      if (errno == ERANGE || num <= 0 ||
          num > std::numeric_limits<unsigned int>::max())
        throw std::runtime_error("Argument Range Error");
      _vec.push_back(num);
      _lst.push_back(num);
      _deq.push_back(num);
      temp.clear();
    }
  }
  if (_vec.size() < 2) throw std::runtime_error("Argument Count Error");
}

bool PmergeMe::pairComparison(vector &numbers, size_t elementSize,
                              size_t pairCount) {
  vectorIt fir = numbers.begin();
  vectorIt sec;
  for (size_t i = 0; i < pairCount; i++) {
    sec = fir + elementSize;
    if (*fir < *sec)
      fir = std::swap_ranges(fir, sec, sec);
    else
      fir = sec + elementSize;
  }
  // Pair을 이루지 못한 element가 있는지 확인 -> 단, 현재 나의 elementSize 기준
  if (static_cast<size_t>(std::distance(fir, numbers.end())) >= elementSize)
    return true;
  else
    return false;
}

void PmergeMe::pendingElementsInsertion(vector &numbers, bool upFlag,
                                        size_t elemSize, size_t pairCnt) {
  vector largerElements(elemSize * pairCnt);
  vector pendingElements(elemSize * (pairCnt + upFlag));
  vectorIt numbersIt = numbers.begin();
  vectorIt largeIt = largerElements.begin();
  vectorIt pendingIt = pendingElements.begin();
  vectorIt tempIt;

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
  vectorIt low = lgElements.begin();
  vectorIt high = lgElements.end();
  vectorIt mid;
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

// vector와 차이점 : std::advance ( + oprator overloading이 없음)
bool PmergeMe::pairComparison(list &numbers, size_t elementSize,
                              size_t pairCount) {
  listIt fir = numbers.begin();
  listIt sec;
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
  // Pair을 이루지 못한 element가 있는지 확인 -> 단, 현재 나의 elementSize 기준
  if (static_cast<size_t>(std::distance(fir, numbers.end())) >= elementSize)
    return true;
  else
    return false;
}

// vector와 차이점 : std::advance, splice member function
void PmergeMe::pendingElementsInsertion(list &numbers, bool upFlag,
                                        size_t elemSize, size_t pairCnt) {
  list pendingElements;
  list remainElements;
  listIt largeIt = numbers.begin();
  listIt pendingIt = pendingElements.end();
  listIt tempIt;

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

// vector와 차이점 : std::advance, splice member function
void PmergeMe::binarySearchInsertion(list &lgElements, list &pdElements,
                                     listIt &compIt, listIt &endIt,
                                     size_t elemSize) {
  listIt low = lgElements.begin();
  listIt high = lgElements.end();
  listIt mid;
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

// vector와 차이점 : 없음
bool PmergeMe::pairComparison(deque &numbers, size_t elementSize,
                              size_t pairCount) {
  dequeIt fir = numbers.begin();
  dequeIt sec;
  for (size_t i = 0; i < pairCount; i++) {
    sec = fir + elementSize;
    if (*fir < *sec)
      fir = std::swap_ranges(fir, sec, sec);
    else
      fir = sec + elementSize;
  }
  // Pair을 이루지 못한 element가 있는지 확인 -> 단, 현재 나의 elementSize 기준
  if (static_cast<size_t>(std::distance(fir, numbers.end())) >= elementSize)
    return true;
  else
    return false;
}

// vector와 차이점 : 없음
void PmergeMe::pendingElementsInsertion(deque &numbers, bool upFlag,
                                        size_t elemSize, size_t pairCnt) {
  deque largerElements(elemSize * pairCnt);
  deque pendingElements(elemSize * (pairCnt + upFlag));
  dequeIt numbersIt = numbers.begin();
  dequeIt largeIt = largerElements.begin();
  dequeIt pendingIt = pendingElements.begin();
  dequeIt tempIt;

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

// vector와 차이점 : 없음
void PmergeMe::binarySearchInsertion(deque &lgElements, dequeIt &compIt,
                                     dequeIt &endIt, size_t elemSize) {
  dequeIt low = lgElements.begin();
  dequeIt high = lgElements.end();
  dequeIt mid;
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