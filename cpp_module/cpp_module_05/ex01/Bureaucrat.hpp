#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat {
 private:
  const std::string _name;
  int _grade;

  Bureaucrat();

 public:
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &copy);
  ~Bureaucrat();

  Bureaucrat &operator=(const Bureaucrat &copy);

  const std::string &getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();

  void signForm(Form &form);

  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif