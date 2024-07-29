#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
  public:
	PhoneBook();
	~PhoneBook();
	void addContact(const Contact &contact);
	void showContact(int index);
	void showContactsSearch();

  private:
	Contact contacts[8];
	int numContacts;
};

#endif // PHONEBOOK_HPP