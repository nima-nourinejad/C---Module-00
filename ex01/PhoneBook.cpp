#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <string>
#include <regex>
#include <iomanip>

PhoneBook::PhoneBook() : numContacts(0) {}

PhoneBook::~PhoneBook() {}

int PhoneBook::oldestContact() const
{
	int oldest = 0;
	for (int i = 1; i < 8; i++)
	{
		if (this->contacts[i].getContactIndex() < contacts[oldest].getContactIndex())
			oldest = i;
	}
  return oldest;
}

void PhoneBook::addContact(const Contact &contact) {
  if (numContacts < 8) {
    contacts[numContacts] = contact;
    ++numContacts;
  }
  else
    this->contacts[oldestContact()] = contact;
}

void PhoneBook::showOneContact(int index) {

  if (index < 1 || index > numContacts)
    std::cerr << "Invalid index." << std::endl;
  else {
    std::cout << "First Name: " << contacts[index - 1].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index - 1].getLastName() << std::endl;
    std::cout << "Phone: " << contacts[index - 1].getPhoneNumber() << std::endl;
    std::cout << "Nickname: " << contacts[index - 1].getNickName() << std::endl;
    std::cout << "Darkest secret: " << contacts[index - 1].getDarkestSecret() << std::endl;
  }
}

void printTen(const std::string &str) {
  std::string temp;

  if (str.length() > 10)
	{
		temp = str.substr(0, 9);
		temp += ".";
	}
	else
		temp = str;
  std::cout << std::setw(10) << std::right << temp;
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

void PhoneBook::search(){
	PhoneBook::showContactsInSearch();
	std::cout << "Enter the index of the contact you want to see: ";
	std::string input;
	std::getline(std::cin, input);
	if (std::cin.eof()) {
        std::cin.clear();
		std::cout << std::endl;
        return ;
      }
	if (input.length() == 1 && input[0] >= '1' && input[0] <= '8') {
		int index = input[0] - '0';
		PhoneBook::showOneContact(index);
	} else
		std::cerr << "Invalid index." << std::endl;
}

int valid_data(std::string str, std::string type)
{
	if (str.empty())
	{
		std::cerr << type << " cannot be empty. Please try again." << std::endl;
		return (0);
	}
	std::regex non_digit("\\D");
	std::regex non_space("\\S");
	if (type == "Phone number" && std::regex_search(str, non_digit))
	{
		std::cerr << "Phone number must contain only digits. Please try again." << std::endl;
		return (0);
	}
	else if (type != "Phone number" && !std::regex_search(str, non_space))
	{
		std::cerr << type << " can not only contain spaces. Please try again." << std::endl;
		return (0);
	}
	return (1);
}

int gettingInfo(std::string &str, std::string type)
{

	while (!std::cin.eof())
	{
		std::cout << "Enter your " << type << ": ";
		std::getline(std::cin, str);
		if (std::cin.eof() || valid_data(str, type))
			break;
	}
	if (std::cin.eof())
	{
		std::cin.clear();
		std::cout << std::endl;
		return (1);
	}
	return (0);
}


int gettingALLInfo(std::string &firstName, std::string &lastName, std::string &nickName, std::string &phoneNumber, std::string &darkestSecret)
{
	if (gettingInfo(firstName, "First name"))
		return (1);
	if (gettingInfo(lastName, "Last name"))
		return (1);
	if (gettingInfo(nickName, "Nickname"))
		return (1);
	if (gettingInfo(phoneNumber, "Phone number"))
		return (1);
	if (gettingInfo(darkestSecret, "Darkest secret"))
		return (1);
	return (0);
}

void PhoneBook::add()
{
      std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	  if (gettingALLInfo(firstName, lastName, nickName, phoneNumber, darkestSecret))
		  return ;
      Contact contact(firstName, lastName, nickName, phoneNumber,
                      darkestSecret);
      PhoneBook::addContact(contact);
}