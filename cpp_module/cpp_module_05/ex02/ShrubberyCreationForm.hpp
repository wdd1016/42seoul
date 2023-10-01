#ifndef ShrubbberyCreationForm_HPP
#define ShrubbberyCreationForm_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  std::string _target;

  ShrubberyCreationForm();

 public:
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &copy);
  ~ShrubberyCreationForm();

  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

  void execute(Bureaucrat const &executor) const;
};

#endif