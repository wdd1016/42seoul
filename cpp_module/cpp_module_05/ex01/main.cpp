#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 150);
    Form f1("f1", 1, 1);
    Form f2("f2", 150, 150);
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    b2.signForm(f1);
    b1.signForm(f1);
    b2.signForm(f2);
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    b2.signForm(f1);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    Bureaucrat b1("b1", 1);
    Form f1("f1", 0, 1);
    std::cout << b1 << std::endl;
    std::cout << f1 << std::endl;
    b1.signForm(f1);
    std::cout << f1 << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    Bureaucrat b1("b1", 150);
    Form f1("f1", 150, 151);
    std::cout << b1 << std::endl;
    std::cout << f1 << std::endl;
    b1.signForm(f1);
    std::cout << f1 << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
