#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <ctime>

#include "AForm.hpp"

class RobotomyRequestForm : public Form {
 private:
  std::string _target;

  RobotomyRequestForm();

 public:
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &copy);
  ~RobotomyRequestForm();

  RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

  const std::string &getTarget() const;
  void execute(Bureaucrat const &executor) const;
};

#endif
