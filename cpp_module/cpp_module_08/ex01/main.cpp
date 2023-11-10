#include "Span.hpp"

std::vector<int> makeRandomInt(unsigned int n) {
  std::vector<int> solution(n);

  for (unsigned int i = 0; i < n; i++) {
    solution[i] = rand();
  }
  return solution;
}

int main() {
  srand(time(NULL));
  Span firstTest(10000);
  std::vector<int> firstInts = makeRandomInt(9998);

  std::cout << "firstTest" << std::endl;
  try {
    firstTest.addNumbers(firstInts.begin(), firstInts.end());
    firstTest.addNumber(1);
    firstTest.addNumber(55);
    firstTest.addNumber(33);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    std::cout << "firstTest shortestSpan : " << firstTest.shortestSpan()
              << std::endl;
    std::cout << "firstTest longestSpan : " << firstTest.longestSpan()
              << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;

  std::cout << "secondTest" << std::endl;
  Span secondTest(20000);
  std::vector<int> secondInts = makeRandomInt(23000);
  try {
    secondTest.addNumbers(secondInts.begin(), secondInts.end());
    secondTest.addNumber(1);
    secondTest.addNumber(55);
    secondTest.addNumber(33);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    std::cout << "secondTest shortestSpan : " << secondTest.shortestSpan()
              << std::endl;
    std::cout << "secondTest longestSpan : " << secondTest.longestSpan()
              << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;

  std::cout << "thirdTest" << std::endl;
  Span thirdTest(30000);
  std::vector<int> thirdInts = makeRandomInt(23000);
  try {
    thirdTest.addNumbers(thirdInts.begin(), thirdInts.end());
    thirdTest.addNumber(1);
    thirdTest.addNumber(88);
    thirdTest.addNumber(33);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    std::cout << "thirdTest shortestSpan : " << thirdTest.shortestSpan()
              << std::endl;
    std::cout << "thirdTest longestSpan : " << thirdTest.longestSpan()
              << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;

  std::cout << "fourthTest" << std::endl;
  Span fourthTest(200);
  try {
    fourthTest.addNumber(33);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    std::cout << "fourthTest longestSpan : " << fourthTest.longestSpan()
              << std::endl;
    std::cout << "fourthTest shortestSpan : " << fourthTest.shortestSpan()
              << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}