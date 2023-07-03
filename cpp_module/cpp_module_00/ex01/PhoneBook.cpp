#include "PhoneBook.hpp"

int	PhoneBook::findCommand() {
  std::string temp;
  std::cout << "Please enter command [ADD, SEARCH, EXIT] : ";
  std::cin >> temp;
  if (std::cin.eof())
    exit(0);
  else if (temp.compare("ADD") == 0)
    return (ADD);
  else if (temp.compare("SEARCH") == 0)
    return (SEARCH);
  else if (temp.compare("EXIT") == 0)
    return (EXIT);
  else
    return (WRONG);
}

void	PhoneBook::add() {
  int index;

  index = count % 8;
  count++;
  if (count > 0x70000000)
    count -= 0x60000000;
  this->contacts[index].addContact();
}

void  PhoneBook::search() {
  int i;

  std::cout << std::setw(10) << "index" << "|"
  << std::setw(10) << "first name" << "|"
  << std::setw(10) << "last name" << "|"
  << std::setw(10) << "nickname" << "|";
  for (i = 0; i < 8; i++) {
    std::cout << std::setw(10) << i + 1 << "|"
    << std::setw(10) << this->contacts[i].getContact(FIR) << "|"
    << std::setw(10) << this->contacts[i].getContact(LST) << "|"
    << std::setw(10) << this->contacts[i].getContact() << "|";
  }
}

int main() {
  PhoneBook book;
  int		cmd_idx;

  while (1) {
	  cmd_idx = book.findCommand();
	  if (cmd_idx == EXIT) {
      std::cout << "The program quits and the contacts are lost forever!" << std::endl;
  		break;
  	}
	  else if (cmd_idx == ADD)
		  book.add();
	  else if (cmd_idx == SEARCH)
		  book.search();
    else
      std::cout << "Wrong command entered." << std::endl;
  }
}