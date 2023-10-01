#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("defalut", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : Form("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &copy)
    : Form(copy), _target(copy.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &copy) {
  if (this != &copy) {
    Form::operator=(copy);
    this->_target = copy.getTarget();
  }
  return *this;
}

const std::string &PresidentialPardonForm::getTarget() const {
  return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  isExecutable(executor);
  std::cout << "Informs that " << _target
            << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
