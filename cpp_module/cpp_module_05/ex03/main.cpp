#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Intern intern;
  Form *sF = NULL;

  try {
    const char *target = "FirstTarget";
    Bureaucrat bc = Bureaucrat("Farm", 5);

    std::cout << "ShrubberyCreation Form" << std::endl;
    sF = intern.makeForm("shrubbery creation", target);
    bc.signForm(*sF);
    bc.executeForm(*sF);
    delete sF;
    sF = NULL;
    std::cout << std::endl;

    std::cout << "RobotomyRequest Form" << std::endl;
    sF = intern.makeForm("robotomy request", target);
    bc.signForm(*sF);
    bc.executeForm(*sF);
    delete sF;
    sF = NULL;
    std::cout << std::endl;

    std::cout << "PresidentialPardon Form" << std::endl;
    sF = intern.makeForm("presidential pardon", target);
    bc.signForm(*sF);
    bc.executeForm(*sF);
    delete sF;
    sF = NULL;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    if (sF) delete sF;
  }

  std::cout << "\n------------------------------------\n" << std::endl;

  try {
    const char *target = "SecondTarget";
    Bureaucrat bc = Bureaucrat("Salt", 5);

    std::cout << "RobotomyRequest Form" << std::endl;
    sF = intern.makeForm("robotomy request", target);
    bc.signForm(*sF);
    bc.executeForm(*sF);
    delete sF;
    sF = NULL;
    std::cout << std::endl;

    std::cout << "Wrong Form" << std::endl;
    sF = intern.makeForm("it's wrong", target);
    bc.signForm(*sF);
    bc.executeForm(*sF);
    delete sF;
    sF = NULL;

    std::cout << "PresidentialPardon Form" << std::endl;
    sF = intern.makeForm("presidential pardon", target);
    bc.signForm(*sF);
    bc.executeForm(*sF);
    delete sF;
    sF = NULL;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    if (sF) delete sF;
  }

  return 0;
}
