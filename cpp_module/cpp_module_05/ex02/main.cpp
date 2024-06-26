#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    std::string target = "FirstTarget";
    Bureaucrat bc = Bureaucrat("Farm", 5);
    ShrubberyCreationForm sF = ShrubberyCreationForm(target);
    RobotomyRequestForm rF = RobotomyRequestForm(target);
    PresidentialPardonForm pF = PresidentialPardonForm(target);

    std::cout << "ShrubberyCreation Form" << std::endl;
    bc.signForm(sF);
    bc.executeForm(sF);
    std::cout << std::endl;

    std::cout << "RobotomyRequest Form" << std::endl;
    bc.signForm(rF);
    bc.executeForm(rF);
    std::cout << std::endl;

    std::cout << "PresidentialPardon Form" << std::endl;
    bc.signForm(pF);
    bc.executeForm(pF);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "\n------------------------------------\n" << std::endl;

  try {
    std::string target = "SecondTarget";
    Bureaucrat bc = Bureaucrat("Salt", 50);
    ShrubberyCreationForm sF = ShrubberyCreationForm(target);
    RobotomyRequestForm rF = RobotomyRequestForm(target);
    PresidentialPardonForm pF = PresidentialPardonForm(target);

    std::cout << "ShrubberyCreation Form" << std::endl;
    bc.signForm(sF);
    bc.executeForm(sF);
    std::cout << std::endl;

    std::cout << "RobotomyRequest Form" << std::endl;
    bc.signForm(rF);
    bc.executeForm(rF);
    std::cout << std::endl;

    std::cout << "PresidentialPardon Form" << std::endl;
    bc.signForm(pF);
    bc.executeForm(pF);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "\n------------------------------------\n" << std::endl;

  try {
    std::string target = "ThirdTarget";
    Bureaucrat bc = Bureaucrat("Tooth", 1);
    ShrubberyCreationForm sF = ShrubberyCreationForm(target);
    RobotomyRequestForm rF = RobotomyRequestForm(target);
    PresidentialPardonForm pF = PresidentialPardonForm(target);

    std::cout << "ShrubberyCreation Form" << std::endl;
    bc.signForm(sF);
    bc.executeForm(sF);
    std::cout << std::endl;

    std::cout << "RobotomyRequest Form" << std::endl;
    bc.signForm(rF);
    bc.executeForm(rF);
    std::cout << std::endl;

    std::cout << "PresidentialPardon Form" << std::endl;
    bc.signForm(pF);
    bc.executeForm(pF);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "\n------------------------------------\n" << std::endl;

  try {
    std::string target = "FourthTarget";
    Bureaucrat bc = Bureaucrat("Sea", 150);
    ShrubberyCreationForm sF = ShrubberyCreationForm(target);
    RobotomyRequestForm rF = RobotomyRequestForm(target);
    PresidentialPardonForm pF = PresidentialPardonForm(target);

    std::cout << "ShrubberyCreation Form" << std::endl;
    bc.signForm(sF);
    bc.executeForm(sF);
    std::cout << std::endl;

    std::cout << "RobotomyRequest Form" << std::endl;
    bc.signForm(rF);
    bc.executeForm(rF);
    std::cout << std::endl;

    std::cout << "PresidentialPardon Form" << std::endl;
    bc.signForm(pF);
    bc.executeForm(pF);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
