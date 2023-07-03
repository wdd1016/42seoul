#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>

enum e_name {
  FIR, LST, NIC, PHONE, DARK
};

class Contact {
  private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

  public:
    void addContact();
    std::string getContact(int idx);
};

#endif