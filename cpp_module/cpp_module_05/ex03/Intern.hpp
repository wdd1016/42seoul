#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

enum Forms {
  PRESIDENTIAL_PARDON,
  ROBOTOMY_REQUEST,
  SHRUBBERY_CREATION,
  NOT_FOUND
};

class Intern {
 private:
  int findForm(const char *name);

 public:
  Intern();
  Intern(const Intern &copy);
  ~Intern();

  Intern &operator=(const Intern &copy);

  Form *makeForm(const char *name, const char *target);

  class InvaildFormNameException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
};

#endif