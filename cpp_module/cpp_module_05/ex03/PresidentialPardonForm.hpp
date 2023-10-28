#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public Form {
 private:
  std::string _target;

  PresidentialPardonForm();

 public:
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &copy);
  ~PresidentialPardonForm();

  PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

  const std::string &getTarget() const;
  void execute(Bureaucrat const &executor) const;
};

#endif