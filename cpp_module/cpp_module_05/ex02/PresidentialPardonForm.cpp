#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("defalut", 150, 150) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &copy)
    : AForm(copy), _target(copy._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &copy) {
  if (this != &copy) {
    AForm::operator=(copy);
    this->_target = copy._target;
  }
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  std::cout << this->_target << " has been pardoned by Zafod Beeblebrox."
            << std::endl;
}
