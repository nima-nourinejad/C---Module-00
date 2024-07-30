#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
  PhoneBook();
  ~PhoneBook();
  void addContact(const Contact &contact);
  void showOneContact(int index);
  void showContactsInSearch();

private:
  Contact contacts[8];
  int numContacts;
};

#endif // PHONEBOOK_HPP