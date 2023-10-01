#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  std::string _target;

  RobotomyRequestForm();

 public:
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &copy);
  ~RobotomyRequestForm();

  RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

  void execute(Bureaucrat const &executor) const;
};

#endif
