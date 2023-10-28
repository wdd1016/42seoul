#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 private:
  const std::string _name;
  bool _signed;
  const int _signGrade;
  const int _execGrade;

  Form();

 public:
  Form(std::string name, int signGrade, int execGrade);
  Form(const Form &copy);
  virtual ~Form();

  Form &operator=(const Form &copy);

  const std::string getName() const;
  bool getSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;

  void beSigned(const Bureaucrat &b);
  void isExecutable(Bureaucrat const &executor) const;
  virtual void execute(Bureaucrat const &executor) const = 0;

  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class GradeTooLowSignedException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class AlreadySignedException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class GradeTooLowExcutedException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class UnsignedException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif