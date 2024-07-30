#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <string>

int main(void) {
  PhoneBook phoneBook;
  Contact contact;
  int index;
  std::string command;
  std::string input;

  std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
  std::getline(std::cin >> std::ws, command);
  while (command != "EXIT") {
    if (command == "ADD") {
      std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
      while (true) {
        std::cout << "Enter your first name: ";
        std::getline(std::cin >> std::ws, firstName);
        if (!firstName.empty())
          break;
        std::cout << "First name cannot be empty. Please try again."
                  << std::endl;
      }
      while (true) {
        std::cout << "Enter your last name: ";
        std::getline(std::cin >> std::ws, lastName);
        if (!lastName.empty())
          break;
        std::cout << "Last name cannot be empty. Please try again."
                  << std::endl;
      }
      while (true) {
        std::cout << "Enter your nickname: ";
        std::getline(std::cin >> std::ws, nickName);
        if (!nickName.empty())
          break;
        std::cout << "Nickname cannot be empty. Please try again." << std::endl;
      }
      while (true) {
        std::cout << "Enter your phone number: ";
        std::getline(std::cin >> std::ws, phoneNumber);
        if (!phoneNumber.empty())
          break;
        std::cout << "Phone number cannot be empty. Please try again."
                  << std::endl;
      }
      while (true) {
        std::cout << "Enter your darkest secret: ";
        std::getline(std::cin >> std::ws, darkestSecret);
        if (!darkestSecret.empty())
          break;
        std::cout << "Darkest secret cannot be empty. Please try again."
                  << std::endl;
      }
      contact.setFirstName(firstName);
      contact.setLastName(lastName);
      contact.setNickName(nickName);
      contact.setPhoneNumber(phoneNumber);
      contact.setDarkestSecret(darkestSecret);
      phoneBook.addContact(contact);
    } else if (command == "SEARCH") {
      phoneBook.showContactsInSearch();
      std::cout << "Enter the index of the contact you want to see: ";
      std::getline(std::cin >> std::ws, input);
      if (input.length() == 1 && input[0] >= '1' && input[0] <= '8') {
        index = input[0] - '0';
        phoneBook.showOneContact(index);
      } else
        std::cout << "Invalid index." << std::endl;
    }
    std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
    std::getline(std::cin >> std::ws, command);
  }
  return (0);
}
