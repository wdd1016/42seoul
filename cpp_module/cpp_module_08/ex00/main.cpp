#include <deque>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main() {
  std::vector<int> firstTest;
  firstTest.push_back(4);
  firstTest.push_back(1);
  firstTest.push_back(2);
  firstTest.push_back(3);
  std::cout << "We make a vector {4, 1, 2, 3}" << std::endl;
  try {
    std::cout << "We find iterator pointing to 3 with easyfind." << std::endl;
    std::vector<int>::iterator it = easyfind(firstTest, 3);
    std::cout << "We successfully found iterator." << std::endl;
    std::cout << "The iterator is the "
              << std::distance(firstTest.begin(), it) + 1
              << "th in the entire vector." << std::endl
              << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl << std::endl;
  }
  try {
    std::cout << "We find iterator pointing to 5 with easyfind." << std::endl;
    std::vector<int>::iterator it = easyfind(firstTest, 5);
    std::cout << "We successfully found iterator." << std::endl;
    std::cout << "The iterator is the "
              << std::distance(firstTest.begin(), it) + 1
              << "th in the entire vector." << std::endl
              << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl << std::endl;
  }

  std::list<int> secondTest;
  secondTest.push_back(4);
  secondTest.push_back(1);
  secondTest.push_back(2);
  secondTest.push_back(3);
  std::cout << "We make a list ( <-> 4 <-> 1 <-> 2 <-> 3 <-> )" << std::endl;
  try {
    std::cout << "We find iterator pointing to 3 with easyfind." << std::endl;
    std::list<int>::iterator it = easyfind(secondTest, 3);
    std::cout << "We successfully found iterator." << std::endl;
    std::cout << "The iterator is the "
              << std::distance(secondTest.begin(), it) + 1
              << "th in the entire vector." << std::endl
              << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl << std::endl;
  }
  try {
    std::cout << "We find iterator pointing to 5 with easyfind." << std::endl;
    std::list<int>::iterator it = easyfind(secondTest, 5);
    std::cout << "We successfully found iterator." << std::endl;
    std::cout << "The iterator is the "
              << std::distance(secondTest.begin(), it) + 1
              << "th in the entire vector." << std::endl
              << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl << std::endl;
  }

  std::deque<int> thirdTest;
  thirdTest.push_back(4);
  thirdTest.push_back(1);
  thirdTest.push_back(2);
  thirdTest.push_back(3);
  std::cout << "We make a deque ( <-> 4 - 1 - 2 - 3 <-> )" << std::endl;
  try {
    std::cout << "We find iterator pointing to 3 with easyfind." << std::endl;
    std::deque<int>::iterator it = easyfind(thirdTest, 3);
    std::cout << "We successfully found iterator." << std::endl;
    std::cout << "The iterator is the "
              << std::distance(thirdTest.begin(), it) + 1
              << "th in the entire vector." << std::endl
              << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl << std::endl;
  }
  try {
    std::cout << "We find iterator pointing to 5 with easyfind." << std::endl;
    std::deque<int>::iterator it = easyfind(thirdTest, 5);
    std::cout << "We successfully found iterator." << std::endl;
    std::cout << "The iterator is the "
              << std::distance(thirdTest.begin(), it) + 1
              << "th in the entire vector." << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}