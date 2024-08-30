#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
  PhoneBook();
  ~PhoneBook();
//   void addContact(const Contact &contact);
  void search();
  void add();
//   void showOneContact(int index);
//   void showContactsInSearch();

private:
  Contact contacts[8];
  int numContacts;
  void showOneContact(int index);
  void showContactsInSearch();
  void addContact(const Contact &contact);
};

#endif // PHONEBOOK_HPP