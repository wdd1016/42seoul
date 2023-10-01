#ifndef ShrubbberyCreationForm_HPP
#define ShrubbberyCreationForm_HPP

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public Form {
 private:
  std::string _target;

  ShrubberyCreationForm();

 public:
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &copy);
  ~ShrubberyCreationForm();

  const std::string &getTarget() const;
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

  void execute(Bureaucrat const &executor) const;
};

#endif