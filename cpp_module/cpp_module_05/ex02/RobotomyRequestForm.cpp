#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("defalut", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : Form(copy), _target(copy.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &copy) {
  if (this != &copy) {
    Form::operator=(copy);
    this->_target = copy.getTarget();
  }
  return *this;
}

const std::string &RobotomyRequestForm::getTarget() const { return (_target); }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  isExecutable(executor);
  srand(time(NULL));
  if (rand() % 2 == 0) {
    std::cout << "Informs that " << _target
              << " has been robotomized successfully." << std::endl;
  } else {
    std::cout << "Informs that " << _target << "'s robotization surgery failed."
              << std::endl;
  }
}
