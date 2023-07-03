#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

enum e_command {
  WRONG, ADD, SEARCH, EXIT
};

class PhoneBook {
  private:
    Contact contacts[8];
    int     count;

  public:
    PhoneBook() { count = 0; }
    int   findCommand();
    void  add();
    void  search();
};

#endif