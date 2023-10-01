#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("defalut", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : Form(copy), _target(copy.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &copy) {
  if (this != &copy) {
    Form::operator=(copy);
    this->_target = copy.getTarget();
  }
  return *this;
}

const std::string &ShrubberyCreationForm::getTarget() const {
  return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  isExecutable(executor);

  std::ofstream file(getTarget() + "_shrubbery");
  if (file.is_open() == false)
    throw std::runtime_error("The file could not be opened.");
  file << "   *    *  ()   *   *\n"
       << "*        * /\\         *\n"
       << "      *   /i\\\\    *  *\n"
       << "    *     o/\\\\  *      *\n"
       << " *       ///\\i\\    *\n"
       << "     *   /*/o\\\\  *    *\n"
       << "   *    /i//\\*\\      *\n"
       << "        /o/*\\\\i\\   *\n"
       << "  *    //i//o\\\\\\\\     *\n"
       << "    * /*////\\\\\\\\i\\*\n"
       << " *    //o//i\\\\*\\\\\\   *\n"
       << "   * /i///*/\\\\\\\\\\o\\   *\n"
       << "  *    *   ||     *    \n";
  file.close();
}