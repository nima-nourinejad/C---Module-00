#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : numContacts(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact &contact) {
  if (numContacts < 8) {
    contacts[numContacts] = contact;
    ++numContacts;
  } else {
    for (int i = 1; i < 8; i++) {
      contacts[i - 1] = contacts[i];
    }
    contacts[7] = contact;
  }
}

void PhoneBook::showOneContact(int index) {
  Contact contact;

  if (index < 1 || index > numContacts)
    std::cout << "Invalid index." << std::endl;
  else {
    contact = contacts[index - 1];
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Phone: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Nickname: " << contact.getNickName() << std::endl;
    std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
  }
}

void printTen(const std::string &str) {
  int len;

  len = static_cast<int>(str.length());
  for (int i = 0; i < 10 - len; i++)
    std::cout << " ";
  for (int i = 0; i < 9 && i < len; i++)
    std::cout << str[i];
  if (len > 10)
    std::cout << ".";
}

void PhoneBook::showContactsInSearch() {
  std::cout << "     Index|First name| Last name|  Nickname" << std::endl;
  for (int i = 0; i < numContacts; i++) {
    Contact contact = contacts[i];
    std::cout << "         " << (i + 1) << "|";
    std::string str = contact.getFirstName();
    printTen(str);
    std::cout << "|";
    str = contact.getLastName();
    printTen(str);
    std::cout << "|";
    str = contact.getNickName();
    printTen(str);
    std::cout << std::endl;
  }
}