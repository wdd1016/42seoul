#include "Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade)
    : _name(name),
      _signed(false),
      _signGrade(signGrade),
      _execGrade(execGrade) {
  if (signGrade < 1 || execGrade < 1) {
    throw Form::GradeTooHighException();
  } else if (signGrade > 150 || execGrade > 150) {
    throw Form::GradeTooLowException();
  }
}

Form::Form(const Form &copy)
    : _name(copy._name),
      _signed(copy._signed),
      _signGrade(copy._signGrade),
      _execGrade(copy._execGrade) {}

Form::~Form() {}

Form &Form::operator=(const Form &copy) {
  if (this == &copy) return (*this);
  _signed = copy._signed;
  std::cerr << "Form can't change name, signGrade or execGrade" << std::endl;
  return (*this);
}

const std::string &Form::getName() const { return (_name); }

bool Form::getSigned() const { return (_signed); }

int Form::getSignGrade() const { return (_signGrade); }

int Form::getExecGrade() const { return (_execGrade); }

void Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > _signGrade) {
    throw Form::GradeTooLowException();
  } else if (_signed == true) {
    throw Form::AlreadySignedException();
  }
  _signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return ("The grade is too high.");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("The grade is too low.");
}

const char *Form::AlreadySignedException::what() const throw() {
  return ("The form is already signed.");
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
  out << form.getName() << " form, signed: " << form.getSigned()
      << ", sign grade: " << form.getSignGrade()
      << ", exec grade: " << form.getExecGrade();
  return (out);
}
