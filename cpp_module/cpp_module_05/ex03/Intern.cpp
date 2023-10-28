#include "Intern.hpp"

int Intern::findForm(const char *name) {
  const std::string forms[3] = {"presidential pardon", "robotomy request",
                                "shrubbery creation"};

  for (int i = 0; i < 3; i++) {
    if (forms[i] == name) return i;
  }
  return NOT_FOUND;
}

Intern::Intern() {}

Intern::Intern(const Intern &copy) { *this = copy; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &copy) {
  if (this != &copy) {
    return *this;
  }
  return *this;
}

Form *Intern::makeForm(const char *name, const char *target) {
  switch (findForm(name)) {
    case PRESIDENTIAL_PARDON:
      std::cout << "Intern creates PresidentialPardonForm" << std::endl;
      return (new PresidentialPardonForm(target));
    case ROBOTOMY_REQUEST:
      std::cout << "Intern creates RobotomyRequestForm" << std::endl;
      return (new RobotomyRequestForm(target));
    case SHRUBBERY_CREATION:
      std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
      return (new ShrubberyCreationForm(target));
    default:
      throw InvaildFormNameException();
  }
}

const char *Intern::InvaildFormNameException::what() const throw() {
  return ("The form name is invalid.");
}