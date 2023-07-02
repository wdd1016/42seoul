#include "Contact.hpp"

void Contact::addContact() {
	std::cout << "Please enter contact details." << std::endl;
	std::cout << "First Name : ";
  std::cin >> this->firstName;
	std::cout << "Last Name : ";
  std::cin >> this->lastName;
	std::cout << "Nickname : ";
  std::cin >> this->nickName;
	std::cout << "Phone Number : ";
  std::cin >> this->phoneNumber;
  std::cout << "Darkest Secret : ";
  std::cin >> this->darkestSecret;
}

std::string Contact::getContact(int idx) {

}