#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
  PhoneBook();
  ~PhoneBook();
  void search();
  void add();

private:
  Contact contacts[8];
  int numContacts;
  void showOneContact(int index);
  void showContactsInSearch();
  void addContact(const Contact &contact);
  int oldestContact() const;
};

#endif // PHONEBOOK_HPP