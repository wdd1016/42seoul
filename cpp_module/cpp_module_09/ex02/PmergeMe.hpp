#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <utility>
#include <vector>

typedef std::pair<std::vector<int>, std::vector<int> > vPair;
typedef std::vector<vPair> vPairs;

typedef std::pair<std::list<int>, std::list<int> > lPair;
typedef std::list<lPair> lPairs;

typedef std::pair<std::deque<int>, std::deque<int> > dPair;
typedef std::deque<dPair> dPairs;

class PmergeMe {
 private:
 public:
  PmergeMe();
  ~PmergeMe();

  template <typename Container, typename ContainerForPairs>
  void makePairs(ContainerForPairs &emptyPairs, Container &cntr) {
    typename Container::iterator it;
    int a;
    int b;

    for (it = cntr.begin(); it != cntr.end(); it++) {
      a = *it;
      it++;
      if (it == cntr.end()) {
        it--;
        emptyPairs.push_back(
            std::make_pair(Container(it, cntr.end()), Container()));
        break;
      }
      b = *it;
      if (a >= b) {
        emptyPairs.push_back(std::make_pair(Container(), Container()));
        emptyPairs.back().first.push_back(a);
        emptyPairs.back().second.push_back(b);
      } else {
        emptyPairs.push_back(std::make_pair(Container(), Container()));
        emptyPairs.back().first.push_back(b);
        emptyPairs.back().second.push_back(a);
      }
    }
  }

  template <typename ContainerForPairs>
  void combinePairs(ContainerForPairs &somePairs) {
    while (somePairs.size() > 2) {
      typename ContainerForPairs::iterator it = somePairs.begin();

      while (it != somePairs.end()) {
        typename ContainerForPairs::iterator nextIt = it;

        nextIt++;
        if (nextIt == somePairs.end()) break;
        (*it).first.insert((*it).first.end(), (*it).second.begin(),
                           (*it).second.end());
        (*nextIt).first.insert((*nextIt).first.end(), (*nextIt).second.begin(),
                               (*nextIt).second.end());
        if ((*it).first.front() >= (*nextIt).first.front()) {
          (*it).second.swap((*nextIt).first);
          it = somePairs.erase(nextIt);
        } else {
          (*nextIt).second.swap((*it).first);
          it = somePairs.erase(it);
          it++;
        }
      }
    }
  }

  // template <typename ContainerForPairs>
  void devideInsertionSortPairs(vPairs &twoPairs) {}
};

#endif