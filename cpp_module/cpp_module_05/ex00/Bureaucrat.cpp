#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name), _grade(grade) {
  if (_grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (_grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
    : _name(copy.getName()), _grade(copy.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
  if (this == &copy) return (*this);
  _grade = copy.getGrade();
  std::cerr << "Bureaucrat can't change name" << std::endl;
  return (*this);
}

const std::string &Bureaucrat::getName() const { return (_name); }

int Bureaucrat::getGrade() const { return (_grade); }

void Bureaucrat::incrementGrade() {
  if (_grade - 1 < 1) throw Bureaucrat::GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrementGrade() {
  if (_grade + 1 > 150) throw Bureaucrat::GradeTooLowException();
  _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Bureaucrat grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Bureaucrat grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
  out << b.getName() << ", bureaucrat grade " << b.getGrade();
  return (out);
}
