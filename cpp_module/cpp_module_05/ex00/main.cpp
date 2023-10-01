#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat b1("bure_1", 1);
    std::cout << b1 << std::endl;
    b1.incrementGrade();
    std::cout << b1 << std::endl;
    b1.incrementGrade();
    std::cout << b1 << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    Bureaucrat b2("bure_2", 150);
    std::cout << b2 << std::endl;
    b2.decrementGrade();
    std::cout << b2 << std::endl;
    b2.decrementGrade();
    std::cout << b2 << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    Bureaucrat b3("bure_3", 0);
    std::cout << b3 << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    Bureaucrat b4("bure_4", 151);
    std::cout << b4 << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    Bureaucrat b5("bure_5", 5);
    std::cout << b5 << std::endl;
    b5.incrementGrade();
    std::cout << b5 << std::endl;
    b5.incrementGrade();
    std::cout << b5 << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    Bureaucrat b6("bure_6", 140);
    std::cout << b6 << std::endl;
    b6.decrementGrade();
    std::cout << b6 << std::endl;
    b6.decrementGrade();
    std::cout << b6 << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
